#include "header.h"

void shuffle(struct card wDeck[52], struct card cards[52])
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
			row = rand() % 52;
		} while (wDeck[row].id != -1);

		/* place card number in chosen slot of deck */
		wDeck[row] = cards[card];
		printf("Placed card id %d at position %d\n", cards[card].id, row);
	}
}
void deal(struct card wDeck[52], struct card hand[5], struct card dummy, int deckpos)
{

	int card = 0;   /* card counter */

	/* deal each of the 52 cards */
	for (card = deckpos; card < deckpos+5; card++)
	{
		if (wDeck[card].id >= 0)
		{	
			hand[card - deckpos] = wDeck[card];
			printf("Card in hand at positiond %d has id %d, and is a %s of %s\n", card - deckpos, wDeck[card].id, wDeck[card].faces, wDeck[card].suits);
			wDeck[card] = dummy;
		}
	}
	deckpos = card;
}
void init_cards(struct card cards[52], const char* wFace[], const char* wSuit[])
{
	int counter = 0;
		for (int i = 0; i < 52; i = i + 4)
		{
			for (int j = 0; j < 4; j++)
			{
				cards[j + i].face = counter;
				cards[j + i].faces = wFace[counter];
			}
			counter = counter + 1;
		}

		counter = 0;

		for (int k = 0; k < 13; k++)
		{
			for (int l = 0; l < 4; l++)
			{
				cards[counter].suit = l;
				cards[counter].suits = wSuit[l];
				cards[counter].id = counter;
				counter = counter + 1;
			}
		}
}
void print_cards(struct card cards[52])
{
	for (int i = 0; i < 52; i++)
	{
		printf("I is %d\nCard of face %s, (%d) and and suit of %s (%d) has an ID of %d.\n", i, cards[i].faces, cards[i].face, cards[i].suits, cards[i].suit, cards[i].id);
	}
}