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
int deal(struct card wDeck[52], struct card hand[5], struct card dummy, int deckpos)
{

	int card = 0;   /* card counter */

	/* deal each of the 52 cards */
	for (card = deckpos; card < deckpos+5; card++)
	{
		if (wDeck[card].id >= 0)
		{	
			hand[card - deckpos] = wDeck[card];
			printf("Card in hand at positiond %d has id %d\n", (card - deckpos), wDeck[card].id);
			wDeck[card] = dummy;
		}
	}
	deckpos = card;
	return deckpos;
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
void determiner(struct card hand[5], int combos[10])
{

	int frequency_table[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	int frequency_table2[4] = {0,0,0,0};
	int index = 0, pairs = 0, toak = 0, straight = 0, rf = 0;
	for (int i = 0; i < 5; i++)
	{
		index = hand[i].face;
		frequency_table[index]= frequency_table[index]+1;
	}
	for (int i = 0; i < 5; i++)
	{
		index = hand[i].suit;
		frequency_table2[index]= frequency_table2[index]+1;
	}
	printf("Ones %d\n", frequency_table[0]);
	printf("Twos %d\n", frequency_table[1]);
	printf("Threes %d\n", frequency_table[2]);
	printf("Fours %d\n", frequency_table[3]);
	printf("Fives %d\n", frequency_table[4]);
	printf("Sixes %d\n", frequency_table[5]);
	printf("Sevens %d\n", frequency_table[6]);
	printf("Eights %d\n", frequency_table[7]);
	printf("Nines %d\n", frequency_table[8]);
	printf("Tens %d\n", frequency_table[9]);
	printf("Jacks %d\n", frequency_table[10]);
	printf("Queens %d\n", frequency_table[11]);
	printf("Kings %d\n", frequency_table[12]);
	printf("Hearts %d\n", frequency_table2[0]);
	printf("Diamonds %d\n", frequency_table2[1]);
	printf("Clubs %d\n", frequency_table2[2]);
	printf("Spades %d\n", frequency_table2[3]);

	for (int i = 0; i < 13; i++)
	{
		if (frequency_table[i] == 2)
		{
			printf("A pair is possible\n");
			combos[1] = 1;
			
			pairs = pairs + 1;
		}
		if (frequency_table[i] == 3)
		{
			combos[3] = 1;
			printf("A three of a kind is possible\n");
			toak = toak + 1;
		}
		if (frequency_table[i] == 4)
		{
			printf("A four of a kind is possible\n");
			combos[7] = 1;
		}
		if (pairs >= 2)
		{
			printf("Two pairs is possible\n");
			combos[2] = 1;
		}
		if (pairs > 0 && toak > 0)
		{
			printf("A full house is possible\n");
			combos[6] = 1;
		}
	}
	for (int i = 12; i >= 0; i--)
	{
		if (frequency_table[0] != 0)
		{
			printf("Your high card is at position %d\n", 0);
			combos[0] = 1;
			break;
		}
		if (frequency_table[i] != 0)
		{
			printf("Your high card is at position %d\n", i);
			break;
		}
	}
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (frequency_table[i + j] == 1)
			{
				straight = straight + 1;
			}
		}
		if (straight == 5)
		{
			for (int k = 0; k < 4; k++)
			{
				if (frequency_table2[k] == 4)
				{
					printf("A straight flush is possible\n");
					combos[8] = 1;
				}
			}
			printf("A straight is possible\n");
			combos[4] = 1;
		}
		straight = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		if (frequency_table2[i] == 4)
		{
			printf("A flush is possible\n");
			combos[5] = 1;
		}
	}
	for (int i = 9; i < 13; i++)
	{
		if (frequency_table[i] == 1)
		{
			rf = rf + 1;
		}
	}
	if (frequency_table[0] == 1)
	{
		rf = rf + 1;
	}
	if (rf == 5)
	{
		for (int i = 0; i < 4; i++)
		{
			if (frequency_table2[i] == 4)
			{
				printf("You got a royal flush\n");
				combos[9] = 1;
			}
		}
		printf("A straight is possible\n");
		combos[4] = 1;
	}
}