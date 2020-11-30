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

int pick_turns(int decision[])
{
	printf("Press enter to see who gets to go first\n");
	system("PAUSE");
	system("CLS");
	decision[0] = (rand() % 2 + 1);
	printf("Player %d gets to go first\n", decision[0]);
	system("PAUSE");
	system("CLS");

}

int set_ships(int decision[], char board[10][10], int xcoor, int ycoor, char orientation)
{
	int xcoor = 0, ycoor = 0;

	printf("Player 1, you will now set the position of your ships starting with your carrier\n\nWould you like to set carrier vertically or horizontally?\n\nPlease enter v for vertically or h for horizontally\n");
	scanf(" %c", &orientation);

	while (orientation != 'v' && orientation != 'h')
	{
			printf("Please only enter lowercase character 'v' or 'h' to indicate the orientation you'd like to set your Carrier\n");
			scanf(" %c", &orientation);
	}

	if (orientation == 'v') //Vertical
	{
		printf("Please enter the x y coordinate you'd like to place the top of your cruiser\n");
		scanf("%d%d", &xcoor, &ycoor);
		while (ycoor < 0 || ycoor > 6)
		{
			printf("You cannot place your carrier at %d %d because part or all of the ship will be off the board\nPlease enter a valid x y coordinate\n", xcoor, ycoor);
			scanf("%d%d", &xcoor, &ycoor);
		}
	}
	if (orientation == 'h') //Horizontal
	{

	}
}

int ship_check(char board[10][10], int xcoor, int ycoor, char orientation, int ship)
{
	char point = board[xcoor][ycoor];

	if (orientation == 'h')
	{
		for (int i = xcoor; i < ship + xcoor; i++)
		{
			if (board[i][ycoor] != '~')
			{
				printf("Something is aleady placed there ):\n");
				return 0;
			}
		}
	}
	else if (orientation == 'v')
	{
		for (int i = ycoor; i < ship + ycoor; i++)
		{
			if (board[xcoor][i] != '~')
			{
				printf("Something is aleady placed there ):\n");
				return 0;
			}
		}
	}

	printf("Ship of size %d can be placed at %d %d\n", ycoor, xcoor);
	return 1;
}

int player_ships(char board[10][10])
{
	int x = 0, y = 0, check = 0, check3 = 0;
	char orientation = '\0';
	for (int i = 2; i < 5; i++)
	{
		while (check == 0)
		{
			switch (i)
			{
				case 3;
					while (check3 == 0)
					{
						printf("Please enter the x y coordinate you'd like to place the left-most portion of your %d long ship\nPlease also enter the orientation of your ship either v for vertical or h for horizontal\n", i);
						scanf("%d%*c%d%*c%c%*c")
					}
					printf("Please enter the x y coordinate you'd like to place the left-most portion of your %d long ship\nPlease also enter the orientation of your ship either v for vertical or h for horizontal\n", i);
					scanf("")
			}
				
		}
	}
}
