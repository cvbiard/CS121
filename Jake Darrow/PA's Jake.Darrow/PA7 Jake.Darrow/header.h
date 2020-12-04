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
struct player
{
	double wallet;
	int turn;
	char bet_move;
	char play_again;
	char win;
};

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[]);
void init_cards(struct card cars[52]);
void print_cards(struct card cards[52], const char* wFace[], const char* wSuit[]);
int game_menu();
void ante_up(double pot, struct player player1, struct player cpu);
void decide_turns(struct player player1, struct player cpu);
void player_choose_bet_move(struct player player1);
void disperse_pot(struct player player1, struct player cpu, double pot);
void frequencyc(int dice1[2][5], int frequency_table[6]);