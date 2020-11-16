#include "header.h"

void init_board(char board[10][10])
{
	int vind, hind;
	for (int i = 0; i < 10; i++)
	{
		vind = i;
		for (int i = 0; i < 10; i++)
		{
			hind = i;
			board[vind][hind] = '~';
		}
	}

}
void print_board(char board[10][10])
{
	int vind, hind;
	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for (int i = 0; i < 10; i++)
	{
		vind = i;
		printf("%d", i);
		for (int i = 0; i < 10; i++)
		{
			hind = i;
			printf("|");
			printf("%c", board[vind][hind]);
		}
		printf("|");
		printf("\n");
	}
}
int ship_check(char board[10][10], int x, int y, char r, int ship)
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
			if (board[y][i+x] != '~')
			{
				printf("The ship of size %d cannot be placed at the coords %d, %d because the space %d, %d is occupied by a %c\n", ship, x, y, x, i, board[y][i]);
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
			if (board[i+y][x] != '~')
			{
				printf("The ship of size %d cannot be placed at the coords %d, %d because the space %d, %d is occupied by a %c\n", ship, x, y, x, i, board[i][x]);
				return 0;
			}
		}
	}

	printf("The ship of size %d can be placed at the coords %d, %d\n", ship, x, y);
	return 1;
}
void player_ships(char board[10][10], struct ship ships[5])
{
	int x = 0, y = 0, check = 0, check3 = 0, shipi = 0;
	char r = '\0';
	for (int i = 0; i < 5; i++)
	{
		while (check == 0)
		{
			printf("Please enter the x and y value for where you would like the left-most point of your %s (length %d), as well as if you would like it oriented vertically ('v') or horizontally ('h') all seperated by a space.\n", ships[i].name, ships[i].size);
			scanf("%d%*c%d%*c%c%*c", &x, &y, &r);
			check = ship_check(board, x, y, r, ships[i].size);
			printf("check is: %d\n", check);
		}
		ship_placer(board, x, y, r, ships[i].size, i, ships, 0);
		shipi++;
		printf("Shipi is %d\n", shipi);
		check = 0;
	}
	
}
void ship_placer(char board[10][10], int x, int y, char r, int ship, int shipi, struct ship ships[5], int player)
{
	if (r == 'h')
	{
		for (int i = 0; i < ship; i++)
		{
			if (player == 0)
			{
				ships[shipi].p1pos[0][i] = x;
				ships[shipi].p1pos[1][i] = y;
			}
			else if (player == 1)
			{
				ships[shipi].p2pos[0][i] = x;
				ships[shipi].p2pos[1][i] = y;
			}
			board[y][i + x] = ships[shipi].letter;
		}
	}
	else if (r == 'v')
	{
		for (int i = 0; i < ship; i++)
		{
			if (player == 0)
			{
				ships[shipi].p1pos[0][i] = x;
				ships[shipi].p1pos[1][i] = y;
			}
			else if (player == 1)
			{
				ships[shipi].p2pos[0][i] = x;
				ships[shipi].p2pos[1][i] = y;
			}
			board[i + y][x] = ships[shipi].letter;
		}
	}
	print_2darr(ships[shipi].p1pos);
	print_board(board);
}
void bot_ships(char board[10][10], struct ship ships[5])
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
			check = ship_check(board, x, y, r, ships[i].size);
			printf("check is: %d\n", check);
		}
		ship_placer(board, x, y, r, ships[i].size, i, ships, 1);
		shipi++;
		check = 0;
	}
}
void take_shot(char board[10][10], int x, int y, struct ship ships[5])
{
	/*int xpos = 0, ypos = 0;
	for (int j = 0; j < 5; j++)
	{
		printf("Checking %s\n", ships[j].name);
		for (int i = 0; i < ships[j].size; i++)
		{
			int vind = i;
			for (int i = 0; i < ships[i].size; i++)
			{
				if (i == 0)
				{
					xpos = ships[i].p1pos[i][vind];
				}
				if (i == 1)
				{
					ypos = ships[i].p1pos[i][vind];
				}

			}
			printf("Looking at space %d, %d\n", xpos, ypos);
			if (x == xpos && y == ypos);
			{
				printf("got a hit on %s\n", ships[i].name);
				ships[i].hits[i] = 'x';
			}
		}
	}*/
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