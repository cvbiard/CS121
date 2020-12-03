#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct card
{
	int face;
	int suit;
	int id;
	char* faces;
	char* suits;
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

void shuffle(struct card wDeck[52], struct card cards[52]);
void deal(struct card wDeck[52], struct card hand[5], struct card dummy, int deckposition);
void init_cards(struct card cards[52], const char* wFace[], const char* wSuit[]);
void print_cards(struct card cards[52]);
int game_menu();
void ante_up(double pot, struct player player1, struct player cpu);
void decide_turns(struct player player1, struct player cpu);
void player_choose_bet_move(struct player player1);
void disperse_pot(struct player player1, struct player cpu, double pot);
void frequency_function(int dice1[2][5], int frequency_table[6]);