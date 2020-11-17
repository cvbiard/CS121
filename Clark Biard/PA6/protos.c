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
		printf("  0 1 2 3 4 5 6 7 8 9\n");
		for (int i = 0; i < 10; i++)
		{
			vind = i;
			printf("%d", i);
			for (int i = 0; i < 10; i++)
			{
				hind = i;
				printf("|");
				if (player.board[vind][hind] != '~' && player.board[vind][hind] != 'x')
				{
					printf("~");
				}
				else if (player.board[vind][hind] != '~')
				{
					printf("x");
				}
				else
				{
					printf("~");
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
			printf("Checking space %d, %d\n", x+i, y);
			if (i + x > 9)
			{
				printf("Going out of bounds\n");
				return 0;
			}
			if (player.board[y][i+x] != '~')
			{
				printf("The ship of size %d cannot be placed at the coords %d, %d because the space %d, %d is occupied by a %c\n", ship, x, y, x, i, player.board[y][i]);
				return 0;
			}
		}
	}
	if (r == 'v')
	{
		for (int i = 0; i < ship; i++)
		{
			printf("Checking space %d, %d\n", x, y+i);
			if (i + y > 9)
			{
				printf("Going out of bounds\n");
				return 0;
			}
			if (player.board[i+y][x] != '~')
			{
				printf("The ship of size %d cannot be placed at the coords %d, %d because the space %d, %d is occupied by a %c\n", ship, x, y, x, i, player.board[i][x]);
				return 0;
			}
		}
	}

	printf("The ship of size %d can be placed at the coords %d, %d\n", ship, x, y);
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
			printf("check is: %d\n", check);
		}
		ship_placer(player, x, y, r, ships[i].size, i, ships, 0);
		shipi++;
		printf("Shipi is %d\n", shipi);
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
		}
	}
	else if (r == 'v')
	{
		for (int i = 0; i < ship; i++)
		{
			player.board[i + y][x] = ships[shipi].letter;
		}
	}
	print_board(player, 1);
}
void bot_ships(struct player player, struct ship ships[5])
{
	int x = 0, y = 0, check = 0, check3 = 0, shipi = 0, rot = 0;
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
			printf("check is: %d\n", check);
		}
		ship_placer(player, x, y, r, ships[i].size, i, ships, 1);
		shipi++;
		check = 0;
	}
}
void take_shot(struct player player, int x, int y, struct ship ships[5])
{
	if (player.id == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			if (player.board[y][x] == ships[i].letter)
			{
				printf("Gottem\n");
				ships[i].hitsp1 = ships[i].hitsp1 + 1;
				printf("Hits on this ship: %d\n", ships[i].hitsp1);
				player.board[y][x] = 'x';
				if (ships[i].hitsp1 == ships[i].size - 1)
				{
					ships[i].sunkp1 = 1;
				}
			}
		}
	}
	if (player.id == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			if (player.board[y][x] == ships[i].letter)
			{
				printf("Gottem\n");
				ships[i].hitsp2 = ships[i].hitsp2 + 1;
				printf("Hits on this ship: %d\n", ships[i].hitsp2);
				player.board[y][x] = 'x';
				if (ships[i].hitsp2 == ships[i].size - 1)
				{
					ships[i].sunkp2 = 1;
				}
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
void check_winner(struct ship ships[5])
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
		exit(0);
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
		exit(0);
	}
}