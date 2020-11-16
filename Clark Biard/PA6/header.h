#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

struct ship {

	int size;
	char letter;
	char *name;
	int p1pos[2][5];
	int p2pos[2][5];
	char hits[5];
	char p1r;
	char p2r;

};

void init_board(char board[10][10]);
void print_board(char board[10][10]);
int ship_check(char board[10][10], int x, int y, char r, int ship);
void player_ships(char board[10][10], struct ship ships[5]);
void ship_placer(char board[10][10], int x, int y, char r, int ship, int shipi, struct ship ships[5], int player);
void bot_ships(char board[10][10], struct ship ships[5]);
void take_shot(char board[10][10], int x, int y, struct ship ships[5]);
void print_2darr(int arr[5][5]);
