#define _CRT_SECURE_NO_WARNINGS
#define INIT_CARD  0, 0 ,-1, 0, "string", "string"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



struct card
{
	int face;
	int suit;
	int id;
	int replace;
	char* faces;
	char* suits;
};
struct hand
{
	struct card array[5];
};

void shuffle(struct card wDeck[52], struct card cards[52]);
int deal(struct card wDeck[52], struct card hand[5], struct card dummy, int deckpos);
void init_cards(struct card cars[52], const char* wFace[], const char* wSuit[]);
void print_cards(struct card cards[52]);
void determiner(struct card hand[5], int combos[10], int who);
void get_replace(struct card hand[5]);
void eval(struct card hand[5], int combos[10], struct card highest[1]);
int winner_check(struct card hand1[5], struct card hand2[5], int combos1[10], int combos2[10], struct card highest1[1], struct card highest2[1]);
void print_hand(struct card hand[5]);
int move(int bank,  int pot[1], int prevbet, int fold[1]);
int ai_bet(int bank, int pot[1], int combos[10], int fold[1], int fold2[1]);