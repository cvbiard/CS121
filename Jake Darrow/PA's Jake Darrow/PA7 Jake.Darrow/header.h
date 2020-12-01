#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct card
{
	int face;
	int suit;
	int id;
};
struct hand
{
	struct card array[5];
};

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[]);
void init_cards(struct card cars[52]);
void print_cards(struct card cards[52], const char* wFace[], const char* wSuit[]);
int game_menu();