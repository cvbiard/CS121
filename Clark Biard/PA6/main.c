#include "header.h"

int main(void)
{
	char player_board[MAX_ROWS][MAX_COLS];
	char bot_board[MAX_ROWS][MAX_COLS];
	char ship_letters[5] = { 'd', 's', 'r', 'b', 'c' };
	//struct ship destroyer;
	//destroyer.size = 2;
	//destroyer.letter = 'd';

	//struct ship submarine;
	//submarine.size = 3;
	//submarine.letter = 's';

	//struct ship cruiser;
	//cruiser.size = 3;
	//cruiser.letter = 'r';

	//struct ship battleship;
	//battleship.size = 4;
	//battleship.letter = 'b';

	//struct ship carrier;
	//carrier.size = 5;
	//carrier.letter = 'c';


	init_board(&player_board);
	print_board(&player_board);
	player_ships(&player_board, &ship_letters);
	print_board(player_board);
	return 0;
}