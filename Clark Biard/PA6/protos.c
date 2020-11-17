#include "header.h"

void init_board(struct player player)
{
	int vind, hind;
	for (int i = 0; i < 10; i++)
	{
		vind = i;
		for (int i = 0; i < 10; i++)
		{
			hind = i;
			player.board[vind][hind] = '~';
		}
	}

}
void print_board(struct player player, int hax)
{
	int vind, hind;
	
	if (player.id == 0 || hax == 1)
	{
		printf("     Your Board:\n");
		printf("  0 1 2 3 4 5 6 7 8 9\n");
		for (int i = 0; i < 10; i++)
		{
			vind = i;
			printf("%d", i);
			for (int i = 0; i < 10; i++)
			{
				hind = i;
				printf("|");
				printf("%c", player.board[vind][hind]);
			}
			printf("|");
			printf("\n");
		}
	}
	if (player.id == 1)
	{
		printf("   Opponent's Board:\n");
		printf("  0 1 2 3 4 5 6 7 8 9\n");
		for (int i = 0; i < 10; i++)
		{
			vind = i;
			printf("%d", i);
			for (int i = 0; i < 10; i++)
			{
				hind = i;
				printf("|");
				if (player.board[vind][hind] != 'x' && player.board[vind][hind] != 'o')
				{
					printf("~");
				}
				else
				{
					printf("%c", player.board[vind][hind]);
				}
			}
			printf("|");
			printf("\n");
		}
	}
}
int ship_check(struct player player, int x, int y, char r, int ship)
{	
	if (r == 'h')
	{
		for (int i = 0; i < ship; i++)
		{
			if (i + x > 9)
			{
				if (player.id == 0)
				{
					printf("You cannot place your ship there as that would result in parts of your ship being out of bounds.\n");
				}
				return 0;
			}
			if (player.board[y][i+x] != '~')
			{
				if (player.id == 0)
				{
				printf("The ship of size %d cannot be placed at the coords %d, %d because the space %d, %d is occupied by a %c\n", ship, x, y, x, i, player.board[y][i]);
				}
				return 0;
			}
		}
	}
	if (r == 'v')
	{
		for (int i = 0; i < ship; i++)
		{
			if (i + y > 9)
			{
				if (player.id == 0)
				{
					printf("You cannot place your ship there as that would result in parts of your ship being out of bounds.\n");
				}
				return 0;
			}
			if (player.board[i+y][x] != '~')
			{
				if (player.id == 0)
				{
				printf("The ship of size %d cannot be placed at the coords %d, %d because the space %d, %d is occupied by a %c\n", ship, x, y, x, i, player.board[i][x]);
				}
				return 0;
			}
		}
	}
	if (player.id == 0)
	{
		printf("The ship of size %d can be placed at the coords %d, %d\n", ship, x, y);
	}
	return 1;
}
void player_ships(struct player player, struct ship ships[5])
{
	int x = 0, y = 0, check = 0, check3 = 0, shipi = 0;
	char r = '\0';
	for (int i = 0; i < 5; i++)
	{
		while (check == 0)
		{
			printf("Please enter the x and y value for where you would like the left-most point of your %s (length %d), as well as if you would like it oriented vertically ('v') or horizontally ('h') all seperated by a space.\n", ships[i].name, ships[i].size);
			scanf("%d%*c%d%*c%c%*c", &x, &y, &r);
			check = ship_check(player, x, y, r, ships[i].size);
		}
		ship_placer(player, x, y, r, ships[i].size, i, ships, 0);
		shipi++;
		check = 0;
	}
}
void ship_placer(struct player player, int x, int y, char r, int ship, int shipi, struct ship ships[5])
{
	if (r == 'h')
	{
		for (int i = 0; i < ship; i++)
		{
			player.board[y][i + x] = ships[shipi].letter;
			if (player.id == 0)
			{
				system("cls");
				print_board(player, 0);
			}
		}
	}
	else if (r == 'v')
	{
		for (int i = 0; i < ship; i++)
		{
			player.board[i + y][x] = ships[shipi].letter;
			if (player.id == 0)
			{
				system("cls");
				print_board(player, 0);
			}
		}
	}
}
void bot_ships(struct player player, struct ship ships[5])
{
	int x = 0, y = 0, check = 0, shipi = 0, rot = 0;
	char r = '\0';
	for (int i = 0; i < 5; i++)
	{
		while (check == 0)
		{
			x = (rand() % 9);
			y = (rand() % 9);
			rot = (rand() % 2);
			if (rot == 0)
			{
				r = 'h';
			}
			else
			{
				r = 'v';
			}
			check = ship_check(player, x, y, r, ships[i].size);
		}
		ship_placer(player, x, y, r, ships[i].size, i, ships, 1);
		shipi++;
		check = 0;
	}
}
void take_shot(struct player player, struct player players[2], int x, int y, struct ship ships[5], int counter, FILE*output)
{
	if (player.id == 0)
	{
		players[1].shots = players[1].shots + 1;
		for (int i = 0; i < 5; i++)
		{
			if (player.board[y][x] == ships[i].letter)
			{
				printf("It's a hit!\n");
				fprintf(output, "On turn %d, player 2 targeted position %d, %d and scored a hit on their opponent's %s.\n", counter, x, y, ships[i].name);
				ships[i].hitsp1 = ships[i].hitsp1 + 1;
				player.board[y][x] = 'x';
				players[1].hits = players[1].hits + 1;
				if (ships[i].hitsp1 == ships[i].size )
				{
					ships[i].sunkp1 = 1;
					fprintf(output, "On turn %d, player 2 sunk their opponent's %s.\n", counter, ships[i].name);
					printf("Your opponent sunk your %s.\n", ships[i].name);
					
				}
			}
			else if (player.board[y][x] == '~')
			{
				printf("It's a miss...\n");
				fprintf(output, "On turn %d, player 2 targeted position %d, %d and scored a miss.\n", counter, x, y);
				players[1].misses = players[1].misses + 1;
				player.board[y][x] = 'o';
			}
		}
	}
	if (player.id == 1)
	{
		players[0].shots = players[0].shots + 1;
		for (int i = 0; i < 5; i++)
		{
			if (player.board[y][x] == ships[i].letter)
			{
				printf("It's a hit!\n");
				fprintf(output, "On turn %d, player 1 targeted position %d, %d and scored a hit on their opponent's %s.\n", counter, x, y, ships[i].name);
				ships[i].hitsp2 = ships[i].hitsp2 + 1;
				player.board[y][x] = 'x';
				players[0].hits = players[0].hits + 1;
				if (ships[i].hitsp2 == ships[i].size )
				{
					ships[i].sunkp2 = 1;
					printf("You sunk my battleship!\n");
					fprintf(output, "On turn %d, player 1 sunk their opponent's %s.\n", counter, ships[i].name);
				}
			}
			else if (player.board[y][x] == '~')
			{
				printf("It's a miss...\n");
				fprintf(output, "On turn %d, player 1 targeted position %d, %d and scored a miss.\n", counter, x, y);
				players[0].misses = players[0].misses + 1;
				player.board[y][x] = 'o';
			}
		}
	}
}
void print_2darr(int arr[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("Value at position %d, %d of this array is %d\n", i, j, arr[i][j]);
		}
	}
}
int check_winner(struct player players[2], struct ship ships[5])
{
	int counter = 0;
	for (int i = 0; i < 5; i++)
	{
		if (ships[i].sunkp1 == 1)
		{
			counter = counter + 1;
		}
	}
	if (counter == 5)
	{
		printf("Player 2 wins!\n");
		players[1].win = 'w';
		players[0].win = 'l';

		players[0].ratio = (players[0].hits / players[0].misses) * 100;
		players[1].ratio = (players[1].hits / players[1].misses) * 100;
		return 1;
	}
	counter = 0;
	for (int i = 0; i < 5; i++)
	{
		if (ships[i].sunkp2 == 1)
		{
			counter = counter + 1;
		}
	}
	if (counter == 5)
	{
printf("Player 1 wins!\n");
players[0].win = 'w';
players[1].win = 'l';

players[0].ratio = (players[0].hits / players[0].misses) * 100;
players[1].ratio = (players[1].hits / players[1].misses) * 100;
return 1;
	}
	return 0;
}
int game_menu()
{
	int answer = 0;

	while (answer == 0) //big loop is exited if user wants to start game or exit, menu can be reaccessed if user requests rules
	{
		printf("Welcome to Clark's game of Battleship (:\n\nEnter the number associated with the action you'd like to take\n1. Display Game Rules\n2. Start Game\n3. Exit\n");
		scanf("%d%*c", &answer);

		while (answer != 1 && answer != 2 && answer != 3)
		{
			printf("Please enter either 1, 2, or 3 to respond to the previous prompt\n\n"); //Saftey Check while loop to make sure only valid answers are provided
			scanf("%d%*c", &answer);
		}

		if (answer == 1) //Rules
		{
			system("CLS");

			printf("Battleship is a two player Navy game.\nThe objective of the game is to sink all ships in your enemy's fleet.\nThe Player to sink his/her enemy's fleet first wins.\nBoth players' fleets consist of 5 ships that are hidden from the enemy.\nEach ship may be differentiated by its 'size' (besides the Cruiser and Submarine)\nor number of cells it expands on the game board.\nThe Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells,\nSubmarine has 3 cells, and the Destroyer has 2 cells.\n\n");
			printf("Enter 0 to return to the main menu\n");
			scanf("%d%*c", &answer);

			system("CLS");
		}
		else if (answer == 2) // 2 means start game
		{
			system("CLS");
			return answer;
		}
		else if (answer == 3) // 3 Means end game
		{
			system("CLS");
			printf("See ya\n");
			system("PAUSE");
			system("CLS");
			exit(0);
		}
	}
}
int pick_turns()
{
	int decision;
	printf("Press enter to see who gets to go first\n");
	system("PAUSE");
	system("CLS");
	decision = (rand() % 2);
	printf("Player %d gets to go first\n", decision);
	system("PAUSE");
	system("CLS");
	return decision;

}
void pick_shot(struct player player, struct player players[2], struct ship ships[5], int go, int counter, FILE* output)
{
	int x, y, check = 0;
	if (player.id == 0)
	{
		while (check == 0)
		{
			printf("It's your turn to take a shot at your opponent. Please enter the x and y values you would like to shoot, seperated by a space.\n");
			scanf("%d%*c%d%*c", &x, &y);
			if (players[1].board[y][x] == 'x' || players[1].board[y][x] == 'o')
			{
				printf("You have already shot at that position before.\n");
			}
			else
			{
				check = 1;
			}
		}
		take_shot(players[1], players, x, y, ships, counter, output);

	}
	else if (player.id == 1)
	{
		while (check == 0)
		{
			x = (rand() % 9);
			y = (rand() % 9);
			if (players[0].board[y][x] != 'x' && players[0].board[y][x] != 'o')
			{
				check = 1;
			}
		}
		printf("Your opponent is taking a shot at %d, %d on your board!\n", x, y);
		take_shot(players[0], players, x, y, ships, counter, output);
	}
}
void print_stats(struct player players[2], FILE* output)
{
	fprintf(output, "Stats for this game:\n");
	fprintf(output, "Player 1's hits: %d\n", players[0].hits);
	fprintf(output, "Player 1's misses: %d\n", players[0].misses);
	fprintf(output, "Player 1's shots: %d\n", players[0].shots);
	fprintf(output, "Player 1's hit to miss ratio: %lf%\n", players[0].ratio);
	fprintf(output, "Did Player 1 win or lose?: %c\n", players[0].win);
	fprintf(output, "\n");
	fprintf(output, "Player 2's hits: %d\n", players[1].hits);
	fprintf(output, "Player 2's misses: %d\n", players[1].misses);
	fprintf(output, "Player 2's shots: %d\n", players[1].shots);
	fprintf(output, "Player 2's hit to miss ratio: %lf%\n", players[1].ratio);
	fprintf(output, "Did Player 2 win or lose?: %c\n", players[1].win);

}