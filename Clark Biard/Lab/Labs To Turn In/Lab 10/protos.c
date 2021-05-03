#include "header.h"

void init_sentences(char sentences[20][48])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 48; j++)
		{
			sentences[i][j] = 'a';
		}
	}

	//for (int i = 0; i < 20; i++)
	//{
	//	for (int j = 0; j < 48; j++)
	//	{
	//		printf("%c", sentences[i][j]);
	//	}
	//	printf("\n");
	//}
}
void generate_sentences(char* article[], char* noun[], char* verb[], char* preposition[], char* sentence[])
{
	sentence[0] = article[rand()%5];
	sentence[1] = noun[rand() % 5];
	sentence[2] = verb[rand() % 5];
	sentence[3] = preposition[rand() % 5];
	sentence[4] = article[rand() % 5];
	sentence[5] = noun[rand() % 5];
	
}
void print_board(Cell** board, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", i + 1);
		for (int j = 0; j < size; j++)
		{
			printf("%c ", board[j][i].symbol);
		}
		printf("\n");
	}
	printf("  ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", i+1);
	}
	printf("\n");
}
int check_win(Cell** board, int size)
{
	int consecutive = 0;
	int scratch = 0;

	//printf("Checking horizontal for X.\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[j][i].symbol == 'X')
			{
				consecutive = consecutive + 1;
			}
			if (consecutive == size)
			{
				return 1;
			}
			//printf("Looking at %d %d.\n", j, i);
			if (board[j][i].symbol != '-')
			{
				scratch = scratch + 1;
			}
			if (scratch == size * size)
			{
				return 3;
			}
		}
		consecutive = 0;
	}

	//printf("Checking verticle for X.\n");

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j].symbol == 'X')
			{
				consecutive = consecutive + 1;
			}
			if (consecutive == size)
			{
				return 1;
			}
			//printf("Looking at %d %d.\n", i, j);
		}
		consecutive = 0;
	}

	//printf("Checking diag1 for X.\n");
	for (int i = 0; i < size; i++)
	{
		if (board[i][i].symbol == 'X')
		{
			consecutive = consecutive + 1;
		}
		if (consecutive == size)
		{
			return 1;
		}
		//printf("Looking at %d %d.\n", i, i);
	}
	consecutive = 0;

	//printf("Checking diag2 for X.\n");
	for (int i = 0; i < size; i++)
	{
		if (board[i][size - i].symbol == 'X')
		{
			consecutive = consecutive + 1;
		}
		if (consecutive == size)
		{
			return 1;
		}
		//printf("Looking at %d %d.\n", i, size - i);
	}
	consecutive = 0;

	//printf("Checking horizontal for O.\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[j][i].symbol == '0')
			{
				consecutive = consecutive + 1;
			}
			if (consecutive == size)
			{
				return 2;
			}
			//printf("Looking at %d %d.\n", j, i);
		}
		
		consecutive = 0;
	}

	//printf("Checking verticle for O.\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j].symbol == 'O')
			{
				consecutive = consecutive + 1;
			}
			if (consecutive == size)
			{
				return 2;
			}
			//printf("Looking at %d %d.\n", i, j);
		}
		consecutive = 0;
	}

	//printf("Checking diag1 for O.\n");
	for (int i = 0; i < size; i++)
	{
		if (board[i][i].symbol == 'O')
		{
			consecutive = consecutive + 1;
		}
		if (consecutive == size)
		{
			return 2;
		}
		//printf("Looking at %d %d.\n", i, i);
	}
	consecutive = 0;

	//printf("Checking diag2 for O.\n");
	for (int i = 0; i < size; i++)
	{
		if (board[i][size - i].symbol == 'O')
		{
			consecutive = consecutive + 1;
		}
		if (consecutive == size)
		{
			return 2;
		}
		//printf("Looking at %d %d.\n", i, size - i);
	}
	consecutive = 0;

	return 0;
}
void reset_board(Cell** board, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			board[j][i].symbol = '-';
			board[j][i].occupied = 0;
		}
	}
}
void ai_move(Cell** board, int size, int turn)
{
	int randx = rand() % size;
	int randy = rand() % size;
	int found = 0;
	int counter = 0;
	if (turn == 0)
	{
		while (found != 1)
		{
			if (randx <= size && randx > -1 && randy <= size && randy > -1 && board[randx][randy].occupied != 1)
			{
				board[randx][randy].occupied = 1;
				board[randx][randy].symbol = 'O';
				found = 1;
			}
			else
			{
				randx = rand() % size;
				randy = rand() % size;
			}
			counter = counter + 1;
			if (counter == size * size)
			{
				break;
			}
		}
		
	}
	else

	{
		for (int i = 0; i < size; i++)
		{

			for (int j = 0; j < size; j++)
			{
				if (board[j][i].symbol == 'O')
				{
					if (j - 1 > -1 && board[j - 1][i].occupied != 1)
					{
						board[j - 1][i].symbol = 'O';
						board[j - 1][i].occupied = 1;
						break;

					}
					if (j + 1 <= size && board[j + 1][i].occupied != 1)
					{
						board[j + 1][i].symbol = 'O';
						board[j + 1][i].occupied = 1;
						break;
					}
					if (i - 1 > -1 && board[j][i - 1].occupied != 1)
					{
						board[j][i - 1].symbol = 'O';
						board[j][i - 1].occupied = 1;
						break;
					}
					if (i + 1 <= size && board[j][i + 1].occupied != 1)
					{
						board[j][i + 1].symbol = 'O';
						board[j][i + 1].occupied = 1;
						break;
					}
				}
			}

		}
	}
}