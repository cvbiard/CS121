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
		//printf("Placed card id %d at position %d\n", cards[card].id, row);
	}
}
int deal(struct card wDeck[52], struct card hand[5], struct card dummy, int deckpos)
{

	int card = 0;   /* card counter */

	/* deal each of the 52 cards */
	for (card = deckpos; card < deckpos+5; card++)
	{
		if (wDeck[card].id >= 0 && hand[card - deckpos].replace == 0)
		{	
			//printf("Throwing away card %s of %s for a %s of %s\n", hand[card - deckpos].faces, hand[card - deckpos].suits, wDeck[card].faces, wDeck[card].suits);
			hand[card - deckpos] = wDeck[card];
			//printf("Card in hand at positiond %d has id %d and is a %s of %s\n", (card - deckpos), wDeck[card].id, wDeck[card].faces, wDeck[card].suits);
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
		//printf("I is %d\nCard of face %s, (%d) and and suit of %s (%d) has an ID of %d.\n", i, cards[i].faces, cards[i].face, cards[i].suits, cards[i].suit, cards[i].id);
	}
}
void determiner(struct card hand[5], int combos[10], int who)
{

	int frequency_table[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	int frequency_table2[4] = {0,0,0,0};
	int index = 0, pairs = 0, toak = 0, straight = 0, rf = 0;
	
	for (int i = 0; i < 5; i++)
	{
		if (hand[i].face < 0)
		{
			index = 0;
		}
		else
		{
			index = hand[i].face;
		}
		frequency_table[index]= frequency_table[index]+1;
	}
	for (int i = 0; i < 5; i++)
	{
		if (hand[i].suit < 0)
		{
			index = 0;
		}
		else
		{
			index = hand[i].suit;
		}
		frequency_table2[index] = frequency_table2[index]+1;
	}
	/*printf("Ones %d\n", frequency_table[0]);
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
	printf("Spades %d\n", frequency_table2[3]);*/

	for (int i = 0; i < 13; i++)
	{
		if (frequency_table[i] == 2)
		{
			if (who == 0)
			{
				printf("A pair is possible\n");
			}
			combos[1] = 1;
			
			pairs = pairs + 1;
		}
		if (frequency_table[i] == 3)
		{
			combos[3] = 1;
			if (who == 0)
			{
				printf("A three of a kind is possible\n");
			}
			toak = toak + 1;
		}
		if (frequency_table[i] == 4)
		{
			if (who == 0)
			{
				printf("A four of a kind is possible\n");
			}
			combos[7] = 1;
		}
		if (pairs >= 2)
		{
			if (who == 0)
			{
				printf("Two pairs is possible\n");
			}
			combos[2] = 1;
		}
		if (pairs > 0 && toak > 0)
		{
			if (who == 0)
			{
				printf("A full house is possible\n");
			}
			combos[6] = 1;
		}
	}
	for (int i = 12; i >= 0; i--)
	{
		if (frequency_table[0] != 0)
		{
			if (who == 0)
			{
				//printf("Your high card is at position %d\n", 0);
			}
			combos[0] = 1;
			break;
		}
		if (frequency_table[i] != 0)
		{
			if (who == 0)
			{
				//printf("Your high card is at position %d\n", i);
			}
			combos[0] = 1;
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
					if (who == 0)
					{
						printf("A straight flush is possible\n");
					}
					combos[8] = 1;
				}
			}
				if (who == 0)
				{
					printf("A straight is possible\n");
				}
			combos[4] = 1;
		}
		straight = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		if (frequency_table2[i] == 4)
		{
			if (who == 0)
			{
				printf("A flush is possible\n");
			}
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
				if (who == 0)
				{
					printf("You got a royal flush\n");
				}
				combos[9] = 1;
			}
		}
			if (who == 0)
			{
				printf("A straight is possible\n");
			}
		combos[4] = 1;
	}
	for (int i = 0; i < 10; i++)
	{
		//printf("combo at %d is %d\n", i, combos[i]);
	}
}
void get_replace(struct card hand[5])
{
	char vars[5] = { 'n', 'n', 'n', 'n', 'n' };
	for (int i = 0; i < 5; i++)
	{
		printf("Would you like to replace card %d in your hand? Enter 'y' for yes or 'n' for no.\n", i + 1);
		scanf("%c%*c", &vars[i]);
		if (vars[i] == 'y')
		{
			hand[i].replace = 0;
		}
		else
		{
			hand[i].replace = 1;
		}
		system("cls");
	}
}
void eval(struct card hand[5], int combos[10], struct card highest[1])
{
	int frequency_table[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int index = 0;
	for (int i = 0; i < 10; i++)
	{
		//printf("combo at %d is %d\n", i, combos[i]);
	}
	if (combos[0] > 0)
	{
		for (int i = 0; i < 4; i++)
		{
			hand[i].replace = 0;
		}
		hand[4].replace = 1;
	}
	if (combos[1] > 0)
	{
		for (int i = 0; i < 5; i++)
		{
			if (hand[i].face < 0)
			{
				index = 0;
			}
			else
			{
				index = hand[i].face;
			}
			frequency_table[index] = frequency_table[index] + 1;
		}
		for (int i = 0; i < 13; i++)
		{
			if (frequency_table[i] == 2)
			{
				for (int j = 0; j < 5; j++)
				{
					if (hand[j].face != i)
					{
						hand[j].replace = 0;
					}
					else
					{
						hand[j].replace = 1;
						if (highest[0].face < hand[j].face)
						{
							highest[0] = hand[j];
						}
					}
				}
			}
		}
	}
	if (combos[2] > 0)
	{
		for (int i = 0; i < 5; i++)
		{
			if (hand[i].face < 0)
			{
				index = 0;
			}
			else
			{
				index = hand[i].face;
			}
			frequency_table[index] = frequency_table[index] + 1;
		}
		for (int i = 0; i < 13; i++)
		{
			if (frequency_table[i] == 2)
			{
				for (int j = 0; j < 5; j++)
				{
					if (hand[j].face != i)
					{
						hand[j].replace = 0;
					}
				}
			}
		}
	}
	if (combos[3] > 0)
	{
		for (int i = 0; i < 5; i++)
		{
			if (hand[i].face < 0)
			{
				index = 0;
			}
			else
			{
				index = hand[i].face;
			}
			frequency_table[index] = frequency_table[index] + 1;
		}
		for (int i = 0; i < 13; i++)
		{
			if (frequency_table[i] == 3)
			{
				for (int j = 0; j < 5; j++)
				{
					if (hand[j].face != i)
					{
						hand[j].replace = 0;
					}
					else
					{
						hand[j].replace = 1;
						if (highest[0].face < hand[j].face)
						{
							highest[0] = hand[j];
						}
					}
				}
			}
		}
	}
	if (combos[7] > 0)
	{
		for (int i = 0; i < 5; i++)
		{
			if (hand[i].face < 0)
			{
				index = 0;
			}
			else
			{
				index = hand[i].face;
			}
			frequency_table[index] = frequency_table[index] + 1;
		}
		for (int i = 0; i < 13; i++)
		{
			if (frequency_table[i] == 4)
			{
				for (int j = 0; j < 5; j++)
				{
					if (hand[j].face != i)
					{
						hand[j].replace = 0;
					}
					else
					{
						hand[j].replace = 1;
						if (highest[0].face < hand[j].face)
						{
							highest[0] = hand[j];
						}
					}
				}
			}
		}
	}
	if (combos[4] > 0 || combos[5] > 0 || combos[6] > 0 || combos[8] > 0 || combos[9] > 0)
	{
		for (int i = 0; i < 5; i++)
		{
			hand[i].replace = 1;
			if (highest[0].face < hand[i].face)
			{
				highest[0] = hand[i];
			}
		}
	}
}
int winner_check(struct card hand1[5], struct card hand2[5], int combos1[10], int combos2[10], struct card highest1[1], struct card highest2[1])
{
	int comb1 = 0, comb2 = 0;

	for (int i = 0; i < 10; i++)
	{
		if (combos1[i] > 0)
		{
			comb1 = i;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (combos2[i] > 0)
		{
			comb2 = i;
		}
	}

	if (comb1 > comb2)
	{
		return 0;
	}
	else if (comb1 < comb2)
	{
		return 1;
	}

	if (comb1 == comb2)
	{
		if (highest1[0].face > highest2[0].face)
		{
			return 0;
		}
		else if (highest1[0].face < highest2[0].face)
		{
			return 1;
		}
	}
}
void print_hand(struct card hand[5])
{
	printf("Your hand:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("An %s of %s\n", hand[i].faces, hand[i].suits);
	}
}
int move(int bank, int pot[1], int prevbet, int fold[1])
{
	char move = '\0';
	int bet = 0;

	if (prevbet == -1)
	{
		printf("Would you like to bet, fold, or go all in? Enter a 'b', 'f' or 'a' respectively.\n");
		scanf("%c%*c", &move);
		
		system("cls");

		if (move == 'b')
		{
			printf("How much would you like to bet? Currently, your bank contains $%d.\n", bank);
			scanf("%d%*c", &bet);
			
			system("cls");
			bank = bank - bet;
			pot[0] = pot[0] + bet;
			return bank;
		}
		if (move == 'f')
		{
			printf("You are withdrawing from the round.\n");
			
			system("cls");
			fold[0] = 1;
			return bank;
		}
		if (move == 'a')
		{
			printf("You are betting everything, $%d.\n", bank);
			
			system("cls");
			pot[0] = bank;
			bank = 0;
			return bank;
		}
	}
	if (prevbet > -1)
	{
		printf("Would you like to call, raise, fold, or go all in? Enter a 'c', 'r', 'f' or 'a' respectively.\n");
		scanf("%c%*c", &move);
		
		system("cls");

		if (move == 'c')
		{
			printf("You called your opponent, betting $%d\n", prevbet);
			
			system("cls");
			bank = bank - prevbet;
			pot[0] = pot[0] + prevbet;
			return bank;
		}
		if (move == 'r')
		{
			printf("How much would you like to raise? Currently, your bank contains $%d.\n", bank);
			scanf("%d%*c", &bet);
			printf("You are betting $%d\n", prevbet + bet);
			
			system("cls");
			bank = bank - prevbet + bet;
			pot[0] = pot[0] + prevbet + bet;
			return bank;
		}
		if (move == 'f')
		{
			printf("You are withdrawing from the round.\n");
			
			system("cls");
			fold[0] = 1;
			return bank;
		}
		if (move == 'a')
		{
			printf("You are betting everything, $%d.\n", bank);
			
			system("cls");
			pot[0] = bank;
			bank = 0;
			return bank;
		}
	}
}
int ai_bet(int bank, int pot[1], int combos[10], int fold[1], int fold2[1])
{
	int bet = 0, counter = 0;
	for (int i = 0; i < 10; i++)
	{
		if (combos[i] > 0)
		{
			counter = counter + 1;
		}
	}
	if (counter <= 1)
	{
		fold[0] = 1;
		fold2[0] = 1;
		printf("Your opponent has folded\n");
		return bet;
	}
	for (int i = 0; i < 10; i++)
	{
		if (combos[i] > 0)
		{
			bet = bet + (rand() % 49 + 1) * ((rand() % 4) + 1);
		}
	}
	printf("Your opponent has bet $%d\n", bet);
	bank = bank - bet;
	pot[0] = pot[0] + bet;
	return bet;
}