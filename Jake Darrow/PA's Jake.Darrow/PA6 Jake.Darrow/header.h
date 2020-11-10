#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void init_board(char board[MAX_ROWS][MAX_COLS], int rows, int cols);
void print_board(char board[MAX_ROWS][MAX_COLS], int rows, int cols);

int game_menu();

int pick_turns();

int set_ships();