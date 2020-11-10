#include "header.h"

void init_board(char board[MAX_ROWS][MAX_COLS], int rows, int cols)
{
	for (int row_index = 0; row_index < rows; ++row_index)
	{
		for (int col_index = 0; col_index < cols; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}
}

void print_board(char board[MAX_ROWS][MAX_COLS], int rows, int cols)
{
	printf("    0   1   2   3   4   5   6   7   8   9\n");
	for (int row_index = 0; row_index < rows; ++row_index)
	{
		printf("%d ", row_index);
		for (int col_index = 0; col_index < cols; ++col_index)
		{
			printf("| %c ", board[row_index][col_index]);
		}
		printf("|\n");
	}
}

int game_menu()
{
	int answer = 0;

	while (answer == 0) //big loop is exited if user wants to start game or exit, menu can be reaccessed if user requests rules
	{
		printf("Welcome to Jake's game of Battleship (:\n\nEnter the number associated with the action you'd like to take\n1. Display Game Rules\n2. Start Game\n3. Exit\n");
		scanf("%d%*c", &answer);

		while (answer != 1 && answer != 2 && answer != 3)
		{
			printf("Please enter either 1, 2, or 3 to respond to the previous prompt\n\n"); //Saftey Check while loop to make sure only valid answers are provided
			scanf("%d%*c", &answer);
		}

		if (answer == 1) //Rules
		{
			system("CLS");

			printf("Battleship is a two player Navy game.\nThe objective of the game is to sink all ships in your enemy's fleet.\nThe Player to sink his/her enemy's fleet first wins.\nBoth players' fleets consist of 5 ships that are hidden from the enemy.\nEach ship may be differentiated by its 'size' (besides the Cruiser and Submarine)\nor number of cells it expands on the game board.\nThe Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells,\nSubmarine has 3 cells, and the Destroyer has 2 cells.\n\n");
			printf("Enter 0 to return to the main menu\n");
			scanf("%d%*c", &answer);

			system("CLS");
		}
		else if (answer == 2) // 2 means start game
		{
			system("CLS");
			return answer;
		}
		else if (answer == 3) // 3 Means end game
		{
			system("CLS");
			printf("See ya\n");
			system("PAUSE");
			system("CLS");
			exit(0);
		}
	}
}

int pick_turns()
{
	int decision[1];
	printf("Press enter to see who gets to go first\n");
	system("PAUSE");
	system("CLS");
	decision[0] = (rand() % 2 + 1);
	printf("Player %d gets to go first\n", decision[0]);
	system("PAUSE");
	system("CLS");

}

int set_ships()
{
	char orientation = '\0';
	printf("Player 1, you will now set the position of your ships starting with your carrier\n\nWould you like to set carrier vertically or horizontally?\n\nPlease enter v for vertically or h for horizontally\n");
	scanf(" %c", &orientation);
	
	while (orientation != 'v' && orientation != 'h')
	{
		printf("Please only enter lowercase character 'v' or 'h' to indicate the orientation you'd like to set your Carrier\n");
		scanf(" %c", &orientation);
	}
	if (orientation == 'v') //Vertical
	{

	}
	if (orientation == 'h') //Horizontal
	{

	}
	
}