#include "header.h"

int main(void)
{
	srand((int)time(NULL));
	char player_board[MAX_ROWS][MAX_COLS];
	char bot_board[MAX_ROWS][MAX_COLS];
	
	struct ship destroyer;
	destroyer.size = 2;
	destroyer.letter = 'd';
	destroyer.name = "destroyer";

	struct ship submarine;
	submarine.size = 3;
	submarine.letter = 's';
	submarine.name = "submarine";

	struct ship cruiser;
	cruiser.size = 3;
	cruiser.letter = 'r';
	cruiser.name = "cruiser";

	struct ship battleship;
	battleship.size = 4;
	battleship.letter = 'b';
	battleship.name = "battleship";

	struct ship carrier;
	carrier.size = 5;
	carrier.letter = 'c';
	carrier.name = "carrier";

	struct ship ships[5] = { destroyer, submarine, cruiser, battleship, carrier };

	init_board(player_board);
	init_board(bot_board);
	print_board(player_board);
	print_board(bot_board);
	player_ships(player_board, ships);
	bot_ships(bot_board, ships);
	return 0;
}