#include "header.h"

int main(void)
{
	srand((int)time(NULL));

	struct player bot_display;
	bot_display.id = 2;
	bot_display.board = malloc(MAX_ROWS * sizeof(char*)); // allocates one dimension
	for (int i = 0; i < 10; i++)
	{
		bot_display.board[i] = malloc(MAX_COLS * sizeof(char*)); // allocates the second dimension
	}

	struct player player;
	player.id = 0;
	// allocate it as so...
	player.board = malloc(MAX_ROWS*sizeof(char*)); // allocates one dimension
	for (int i = 0; i < 10; i++) 
	{
		player.board[i] = malloc(MAX_COLS * sizeof(char*)); // allocates the second dimension
	}
	
	struct player bot;
	bot.id = 1;

	bot.board = malloc(MAX_ROWS * sizeof(char*)); // allocates one dimension

	for (int i = 0; i < 10; i++)
	{
		bot.board[i] = malloc(MAX_COLS * sizeof(char*)); // allocates the second dimension
	}

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
	
	init_board(player);
	init_board(bot);
	print_board(player, 0);
	print_board(bot, 0);
	player_ships(player, ships);
	bot_ships(bot, ships);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			
			take_shot(bot, j, i, ships);
			print_board(bot, 0);
			print_board(bot, 1);
			check_winner(ships);
		}
	}
	return 0;
}