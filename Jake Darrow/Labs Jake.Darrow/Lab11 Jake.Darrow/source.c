#include "header.h"

void init_board(char board[MAX_ROWS][MAX_COL], int rows, int col)
{
	for (int row_index = 0; row_index < rows; ++row_index)
	{
		for (int col_index = 0; col_index < col; ++col_index)
		{
			board[row_index][col_index] = ' ';
		}
	}
}

void print_board(char board[MAX_ROWS][MAX_COL], int rows, int col)
{
	printf("   0   1   2\n");
	for (int row_index = 0; row_index < rows; ++row_index)
	{
		printf("%d", row_index);
		for (int col_index = 0; col_index < col; ++col_index)
		{
			printf("| %c ", board[row_index][col_index]);
		}
		printf("|\n");
	}
}

