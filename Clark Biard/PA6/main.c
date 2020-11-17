#include "header.h"

int main(void)
{
	FILE *output = fopen("battleship.log", "w");
	srand((int)time(NULL));
	int turn, counter = 0;

	struct player player;
	player.id = 0;
	// allocate it as so...
	player.board = malloc(MAX_ROWS*sizeof(char*)); // allocates one dimension
	for (int i = 0; i < 10; i++) 
	{
		player.board[i] = malloc(MAX_COLS * sizeof(char*)); // allocates the second dimension
	}
	player.hits = 0;
	player.misses = 0;
	player.shots = 0;
	player.ratio = 0.0;

	struct player bot;
	bot.id = 1;

	bot.board = malloc(MAX_ROWS * sizeof(char*)); // allocates one dimension

	for (int i = 0; i < 10; i++)
	{
		bot.board[i] = malloc(MAX_COLS * sizeof(char*)); // allocates the second dimension
	}
	bot.hits = 0;
	bot.misses = 0;
	bot.shots = 0;
	bot.ratio = 0.0;

	struct ship destroyer;
	destroyer.size = 2;
	destroyer.letter = 'd';
	destroyer.name = "destroyer";
	destroyer.hitsp1 = 0;
	destroyer.hitsp2 = 0;
	destroyer.sunkp1 = 0;
	destroyer.sunkp2 = 0;

	struct ship submarine;
	submarine.size = 3;
	submarine.letter = 's';
	submarine.name = "submarine";
	submarine.hitsp1 = 0;
	submarine.hitsp2 = 0;
	submarine.sunkp1 = 0;
	submarine.sunkp2 = 0;


	struct ship cruiser;
	cruiser.size = 3;
	cruiser.letter = 'r';
	cruiser.name = "cruiser";
	cruiser.hitsp1 = 0;
	cruiser.hitsp2 = 0;
	cruiser.sunkp1 = 0;
	cruiser.sunkp2 = 0;

	struct ship battleship;
	battleship.size = 4;
	battleship.letter = 'b';
	battleship.name = "battleship";
	battleship.hitsp1 = 0;
	battleship.hitsp2 = 0;
	battleship.sunkp1 = 0;
	battleship.sunkp2 = 0;


	struct ship carrier;
	carrier.size = 5;
	carrier.letter = 'c';
	carrier.name = "carrier";
	carrier.hitsp1 = 0;
	carrier.hitsp2 = 0;
	carrier.sunkp1 = 0;
	carrier.sunkp2 = 0;

	struct ship ships[5] = { destroyer, submarine, cruiser, battleship, carrier };
	struct player players[2] = { player, bot };
	
	game_menu();
	turn = pick_turns();
	init_board(player);
	init_board(bot);
	bot_ships(bot, ships);
	print_board(player, 0);
	player_ships(player, ships);

	while (check_winner(players, ships) == 0)
	{
		if (turn == 0)
		{
			system("cls");
			print_board(bot, 0);
			print_board(player, 0);
			pick_shot(player, players, ships, 0, counter, output);
			system("PAUSE");
			system("cls");
			print_board(bot, 0);
			print_board(player, 0);
			pick_shot(bot, players, ships, 0, counter, output);
			system("PAUSE");
			system("cls");
		}
		if (turn == 1)
		{
			system("cls");
			print_board(bot, 0);
			print_board(player, 0);
			pick_shot(bot, players, ships, 0, counter, output);
			system("PAUSE");
			system("cls");
			print_board(bot, 0);
			print_board(player, 0);
			pick_shot(player, players, ships, 0, counter, output);
			system("PAUSE");
			system("cls");
		}
			counter = counter + 1;
	}
	print_stats(players, output);
	fclose(output);
	return 0;
}