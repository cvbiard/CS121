#include "header.h"

int main(void)
{
	int board[MAX_ROWS][MAX_COLS];
	init_board(board);
	print_board(board);
	return 0;
}