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
		printf("I is %d\nCard of face %s, (%d) and and suit of %s (%d) has an ID of %d.\n", i, wFace[cards[i].face], cards[i].face, wSuit[cards[i].suit], cards[i].suit, cards[i].id);
	}
}