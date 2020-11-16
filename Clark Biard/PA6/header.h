#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

struct ship {

	int size;
	char letter;
	int p1xpos;
	int p2xpos;
	int p1ypos;
	int p2ypos;
	char p1r;
	char p2r;

};

void init_board(char board[10][10]);
void print_board(char board[10][10], int player);
int ship_check(char board[10][10], int x, int y, char r, int ship);
void player_ships(char board[10][10], struct ship ships[5]);
void ship_placer(char board[10][10], int x, int y, char r, int ship, int shipi, struct ship ships[5]);
void bot_ships(char board[10][10], struct ship ships[5]);
