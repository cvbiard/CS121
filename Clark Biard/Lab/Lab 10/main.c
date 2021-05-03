#include "header.h"

int main(void)
{

	/*char* article[] = { "the", "a", "one", "some", "any" };
	char* noun[] = { "boy", "girl", "dog", "town", "car" };
	char* verb[] = { "drove", "jumped","ran", "walked", "skipped" };
	char* preposition[] = { "to", "from", "over", "under", "on" };

	char first_letter[] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
	char last_letter[] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0' };

	char dummy_word[] = { "dummyword" };

	char* sentence[] = { dummy_word, dummy_word, dummy_word, dummy_word, dummy_word, dummy_word };

	
	srand(time(NULL));

	generate_sentences(article, noun, verb, preposition, sentence);*/

	int game_done = 0;
	int player = 0;
	int move_row = 0;
	int move_column = 0;
	int invalid = 0;

	srand(time(NULL));

	Game_info p1;
	p1.wins = 0;
	p1.losses = 0;
	p1.total_games_played = 0;

	Game_info p2;
	p2.wins = 0;
	p2.losses = 0;
	p2.total_games_played = 0;

	int win = 0;
	char again = '\0';
	char ai = '\0';

	Cell **board;
	int board_size = 0;
	printf("Please enter a board size.\n");
	scanf("%d%*c", &board_size);

	printf("Would you like to play against another player (enter a) or the computer (enter b)?.\n");
	scanf("%c%*c", &ai);

	board = (Cell **)malloc(board_size * sizeof(Cell*)); // allocates one dimension
	for (int i = 0; i < board_size; i++)
	{
		board[i] = (Cell *)malloc(board_size * sizeof(Cell)); // allocates the second dimension
	}
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			board[j][i].symbol = '-';
			board[j][i].location.row = j;
			board[j][i].location.column = i;
			board[j][i].occupied = 0;
			//printf("%c ", board[j][i].symbol);
		}
		//printf("\n");
	}

	int turn = 0;

	while (game_done != 1)
	{
		system("cls");
		print_board(board, board_size);

		printf("[Player 1] Please enter which row and column you would like to place your X, from 1 to %d.\n", board_size);
		scanf("%d%d%*c", &move_column, &move_row);

		if (move_row-1 > board_size || move_column-1 > board_size || board[move_row-1][move_column-1].occupied == 1)
		{
			invalid = 1;
		}
		while (invalid == 1)
		{
			printf("[Player 1] That space is invalid, please enter which row and column you would like to place your X, from 1 to %d.\n", board_size);
			scanf("%d%d%*c", &move_row, &move_column);
			if (move_row-1 < board_size && move_column-1 < board_size && board[move_row-1][move_column-1].occupied == 0 )
			{
				invalid = 0;
			}
		}

		board[move_row-1][move_column-1].occupied = 1;
		board[move_row-1][move_column-1].symbol = 'X';
		system("cls");
		print_board(board, board_size);

		win = check_win(board, board_size);
		if (win != 0)
		{
			if (win == 3)
			{
				printf("Scratch game!\n");
				p1.total_games_played = p1.total_games_played + 1;
				p2.total_games_played = p2.total_games_played + 1;
			}
			else
			{
				printf("Player %d wins! Play again? y or n.\n", win);
			}
			scanf("%c%*c", &again);

			if (win == 1)
			{
				p1.wins = p1.wins + 1;
				p2.losses = p2.losses + 1;
				p1.total_games_played = p1.total_games_played + 1;
				p2.total_games_played = p2.total_games_played + 1;
			}
			if (win == 2)
			{
				p2.wins = p2.wins + 1;
				p1.losses = p1.losses + 1;
				p1.total_games_played = p1.total_games_played + 1;
				p2.total_games_played = p2.total_games_played + 1;
			}
			if (again == 'y')
			{
				reset_board(board, board_size);
			}
			if (again == 'n')
			{
				game_done = 1;
			}
		}

		if (ai == 'a')
		{
			printf("[Player 2] Please enter which row and column you would like to place your O, from 1 to %d.\n", board_size);
			scanf("%d%d%*c", &move_column, &move_row);

			if (move_row - 1 > board_size || move_column - 1 > board_size || board[move_row - 1][move_column - 1].occupied == 1)
			{
				invalid = 1;
			}
			while (invalid == 1)
			{
				printf("[Player 2] That space is invalid, please enter which row and column you would like to place your O, from 1 to %d.\n", board_size);
				scanf("%d%d%*c", &move_row, &move_column);
				if (move_row - 1 < board_size && move_column - 1 < board_size && board[move_row - 1][move_column - 1].occupied == 0)
				{
					invalid = 0;
				}
			}

			board[move_row - 1][move_column - 1].occupied = 1;
			board[move_row - 1][move_column - 1].symbol = 'O';
		}
		if (ai == 'b')
		{
			printf("AI about to move.\n");
			system("PAUSE");
			ai_move(board, board_size, turn);
		}


		system("cls");
		print_board(board, board_size);

		win = check_win(board, board_size);
		if (win != 0)
		{
			if (win == 3)
			{
				printf("Scratch game!\n");
				p1.total_games_played = p1.total_games_played + 1;
				p2.total_games_played = p2.total_games_played + 1;
			}
			else
			{
				printf("Player %d wins! Play again? y or n.\n", win);
			}
			scanf("%c%*c", &again);

			if (win == 1)
			{
				p1.wins = p1.wins + 1;
				p2.losses = p2.losses + 1;
				p1.total_games_played = p1.total_games_played + 1;
				p2.total_games_played = p2.total_games_played + 1;
			}
			if (win == 2)
			{
				p2.wins = p2.wins + 1;
				p1.losses = p1.losses + 1;
				p1.total_games_played = p1.total_games_played + 1;
				p2.total_games_played = p2.total_games_played + 1;
			}

			if (again == 'y')
			{
				reset_board(board, board_size);
			}
			if (again == 'n')
			{
				game_done = 1;
			}
		}
		turn = turn + 1;
	}
	free(board);

	return 0;
}