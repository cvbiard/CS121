#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10
// :)
struct ship {

	int size;
	char letter;
	char *name;
	int hitsp1;
	int hitsp2;
	int sunkp1;
	int sunkp2;

};
struct player
{
	char **board;
	int id;
	int hits;
	int misses;
	int shots;
	double ratio;
	char win;
};

void init_board(struct player player);
void print_board(struct player player, int hax);
int ship_check(struct player player, int x, int y, char r, int ship);
void player_ships(struct player player, struct ship ships[5]);
void ship_placer(struct player player, int x, int y, char r, int ship, int shipi, struct ship ships[5]);
void bot_ships(struct player player, struct ship ships[5]);
void take_shot(struct player player, struct player players[2], int x, int y, struct ship ships[5], int counter, FILE*output);
void print_2darr(int arr[5][5]);
int check_winner(struct player players[2], struct ship ships[5]);
int game_menu();
int pick_turns();
void pick_shot(struct player player, struct player players[2], struct ship ships[5], int go, int counter, FILE*output);
void print_stats(struct player players[2], FILE*output);
