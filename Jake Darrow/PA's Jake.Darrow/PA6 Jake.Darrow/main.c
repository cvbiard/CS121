#include "header.h"

int main(void)
{
	char board[MAX_ROWS][MAX_COLS] = { {'\0'} };

	init_board(board, MAX_ROWS, MAX_COLS);
	print_board(board, MAX_ROWS, MAX_COLS);

	return 0;
}