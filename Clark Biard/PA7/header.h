#define _CRT_SECURE_NO_WARNINGS
#define INIT_CARD  0, 0 ,-1, 0, "string", "string"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



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
void determiner(struct card hand[5], int combos[10]);
void get_replace(struct card hand[5]);
int ai_eval(struct card hand[5], int combos[10]);
void winner_check(struct card hand1[5], struct card hand2[5], int combos1[10], int combos2[10]);