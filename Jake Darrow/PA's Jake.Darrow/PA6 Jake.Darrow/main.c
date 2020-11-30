#include "header.h"

int main(void)
{
	int decision[1];
	char board[MAX_ROWS][MAX_COLS] = { {'\0'} }, orientation = '\0';
	srand(time(NULL)); //Random based on time

	game_menu();
	pick_turns(decision);
	init_board(board, MAX_ROWS, MAX_COLS);
	print_board(board, MAX_ROWS, MAX_COLS);
	

	return 0;
}