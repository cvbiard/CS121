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
void print_board(char board[10][10], int player)
{
	int vind, hind;
	switch (player)
	{
	case 0:
		printf("Printing player board\n");
		break;
	case 1:
		printf("Printing bot board\n");
		break;
	}
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
		for (int i = x; i < ship + x; i++)
		{
			if (board[i][y] != '~')
			{
				printf("The ship of size %d cannot be placed at the coords %d, %d because the space %d, %d is occupied by a %c\n", ship, x, y, y, i, board[i][y]);
				return 0;
			}
		}
	}
	else if (r == 'v')
	{
		for (int i = y; i < ship + y; i++)
		{
			if (board[x][i] != '~')
			{
				printf("The ship of size %d cannot be placed at the coords %d, %d because the space %d, %d is occupied by a %c\n", ship, x, y, x, i, board[x][i]);
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
	for (int i = 2; i < 6; i++)
	{
		while (check == 0)
		{
			switch (i)
			{
			case 3:
				while (check3 == 0)
				{
					printf("Please enter the x and y value for where you would like the left-most point of your first ship of length %d, as well as if you would like it oriented vertically ('v') or horizontally ('h') all seperated by a space.\n", i);
					scanf("%d%*c%d%*c%c%*c", &x, &y, &r);
					check3 = ship_check(board, x, y, r, i);
					ship_placer(board, x, y, r, i, shipi, ships);
					shipi++;
					printf("Shipi is %d\n", shipi);
				}
				printf("Please enter the x and y value for where you would like the left-most point of your second ship of length %d, as well as if you would like it oriented vertically ('v') or horizontally ('h') all seperated by a space.\n", i);
				scanf("%d%*c%d%*c%c%*c", &x, &y, &r);
				check = ship_check(board, x, y, r, i);
				break;

			default:
				printf("Please enter the x and y value for where you would like the left-most point of your ship of length %d, as well as if you would like it oriented vertically ('v') or horizontally ('h') all seperated by a space.\n", i);
				scanf("%d%*c%d%*c%c%*c", &x, &y, &r);
				check = ship_check(board, x, y, r, i);
				break;
			}
		}
		ship_placer(board, x, y, r, i, shipi, ships);
		shipi++;
		printf("Shipi is %d\n", shipi);
		check = 0;
	}
	
}
void ship_placer(char board[10][10], int x, int y, char r, int ship, int shipi, struct ship ships[5])
{
	/*ships[shipi].p1xpos = x;
	ships[shipi].p1ypos = y;
	ships[shipi].p1r = r;*/

	if (r == 'h')
	{
		for (int i = x; i < ship + x; i++)
		{
			board[y][i] = ships[shipi].letter;
		}
	}
	else if (r == 'v')
	{
		for (int i = y; i < ship + y; i++)
		{
			board[i][x] = ships[shipi].letter;
		}
	}
	print_board(board, 0);
}
void bot_ships(char board[10][10], struct ship ships[5])
{
	int x = 0, y = 0, check = 0, check3 = 0, shipi = 0, rot = 0;
	char r = '\0';
	for (int i = 2; i < 6; i++)
	{
		while (check == 0)
		{
			switch (i)
			{
			case 3:
				while (check3 == 0)
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
					check3 = ship_check(board, x, y, r, i);
					ship_placer(board, x, y, r, i, shipi, ships);
					shipi++;
					printf("Shipi is %d\n", shipi);
				}
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
				check = ship_check(board, x, y, r, i);
				break;

			default:
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
				check = ship_check(board, x, y, r, i);
				break;
			}
		}
		ship_placer(board, x, y, r, i, shipi, ships);
		shipi++;
		printf("Shipi is %d\n", shipi);
		check = 0;
	}
}