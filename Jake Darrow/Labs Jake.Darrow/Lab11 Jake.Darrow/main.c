#include "header.h"

int main(void) {
	//Problem 1
	/*srand(time(NULL));

	char* article[5] = { "the", "a", "one", "some", "any" };
	char* noun[5] = { "boy", "girl", "dog","town","car" };
	char* verb[5] = { "drove", "jumped", "ran", "walked", "skipped" };
	char* preposition[5] = { "to", "from", "over", "under", "on" };


	for (int i = 0; i < 20; i++)
	{
		printf(article[rand() % 5]);
		printf(" ");
		printf(noun[rand() % 5]);
		printf(" ");
		printf(verb[rand() % 5]);
		printf(" ");
		printf(preposition[rand() % 5]);
		printf("\n");
	}*/

	//Problem 2
	typedef struct coordinate

	{
		int row;
		int column;
	} Coordinate;

	typedef struct cell
	{

		int occupied; // 1 if an X or O is in this cell; 0 otherwise
		char symbol; // X for one player, O for the other player
		Coordinate location; // A struct defined above, which represents the position of the cell within the game board
	} Cell;

	char board[MAX_ROWS][MAX_COL] = { {'\0'} };
	
	init_board(board, MAX_ROWS, MAX_COL);
	print_board(board, MAX_ROWS, MAX_COL);


	return 0;
}
