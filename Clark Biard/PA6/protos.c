#include "header.h"

void init_board(int board[10][10])
{
	int vind, hind;
	for (int i = 0; i < 10; i++)
	{
		vind = i;
		for (int i = 0; i < 10; i++)
		{
			hind = i;
			board[vind][hind] = i;
		}
	}

}
void print_board(int board[10][10])
{
	int vind, hind;
	for (int i = 0; i < 10; i++)
	{
		vind = i;
		for (int i = 0; i < 10; i++)
		{
			hind = i;
			printf("%d", board[vind][hind]);
		}
		printf("\n");
	}
}