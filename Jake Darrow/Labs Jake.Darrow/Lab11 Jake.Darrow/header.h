#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 3
#define MAX_COL 3

void init_board(char board[MAX_ROWS][MAX_COL], int rows, int col);
void print_board(char board[MAX_ROWS][MAX_COL], int rows, int col);