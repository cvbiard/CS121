#include "header.h"

int main(void)
{
	srand((int)time(NULL));
	char player_board[MAX_ROWS][MAX_COLS];
	char bot_board[MAX_ROWS][MAX_COLS];
	
	struct ship destroyer;
	destroyer.size = 2;
	destroyer.letter = 'd';

	struct ship submarine;
	submarine.size = 3;
	submarine.letter = 's';

	struct ship cruiser;
	cruiser.size = 3;
	cruiser.letter = 'r';

	struct ship battleship;
	battleship.size = 4;
	battleship.letter = 'b';

	struct ship carrier;
	carrier.size = 5;
	carrier.letter = 'c';

	struct ship ships[5] = { destroyer, submarine, cruiser, battleship, carrier };

	init_board(player_board);
	init_board(bot_board);
	print_board(player_board, 0);
	print_board(bot_board, 1);
	player_ships(player_board, ships);
	bot_ships(bot_board, ships);
	return 0;
}