#include "header.h"

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* deal each of the 52 cards */
	for (card = 1; card <= 52; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}

void init_cards(struct card cards[52])
{
	int counter = 0;
	for (int i = 0; i < 52; i = i + 4)
	{
		for (int j = 0; j < 4; j++)
		{
			cards[j + i].face = counter;
		}
		counter = counter + 1;
	}

	counter = 0;

	for (int k = 0; k < 13; k++)
	{
		for (int l = 0; l < 4; l++)
		{
			cards[counter].suit = l;
			cards[counter].id = counter;
			counter = counter + 1;
		}
	}
}

void print_cards(struct card cards[52], const char* wFace[], const char* wSuit[])
{
	for (int i = 0; i < 52; i++)
	{
		printf("I is %d\nCard of face %s, (%d) and suit of %s (%d) has an ID of %d.\n", i, wFace[cards[i].face], cards[i].face, wSuit[cards[i].suit], cards[i].suit, cards[i].id);
	}
}

int game_menu()
{
	int answer = 0;

	while (answer == 0) //big loop is exited if user wants to start game or exit, menu can be reaccessed if user requests rules
	{
		printf("Welcome to Jake's game of Five Card Draw (:\nEnter the number associated with the action you'd like to take\n1. Print Game Rules\n2. Start a Game of Yahtzee\n3. Exit\n");
		scanf("%d%*c", &answer);

		while (answer != 1 && answer != 2 && answer != 3)
		{
			printf("Please enter either 1, 2, or 3 to respond to the previous prompt\n"); //Saftey Check while loop to make sure only valid answers are provided
			scanf("%d%*c", &answer);
		}

		if (answer == 1) //Rules
		{
			system("CLS");

			printf("Copy and paste the following link into your website browser\nto reach the wikipedia page describing how the game five card draw operates\n\nhttps://en.wikipedia.org/wiki/Five-card_draw\n\n");
			printf("Enter 0 to return to the main menu\n");
			scanf("%d%*c", &answer);
			system("CLS");
		}
		else if (answer == 2) // 2 means start game
		{
			return answer;
		}
		else if (answer == 3) // 3 Means end game
		{
			exit(0);
		}
	}
}

void ante_up(double pot, struct player player1, struct player cpu)
{
	printf("Press enter to place the $5 ante for the round");
	system("PAUSE");
	player1.wallet -= 5;
	cpu.wallet -= 5;
	pot += 10;
	printf("$10 was added to the pot");
	
}

void decide_turns(struct player player1, struct player cpu)
{
	printf("Press enter to see who goes first\n");
	system("PAUSE");
	player1.turn = rand() % 2;
	if (player1.turn = 1)
	{
		cpu.turn = 0;
		printf("CPU goes first");
	}
	else
	{
		cpu.turn = 1;
		printf("Player 1 goes first (:\n");
	}
}