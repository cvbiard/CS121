#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct coordinate
{
    int row;
    int column;
} Coordinate;

typedef struct cell
{
    int occupied; // 1 if an X or O is in this cell; 0 otherwise
    char symbol; // X for one player, O for the other player
    Coordinate location; // A struct defined above, which represents the position of the cell within the game board
} Cell;

typedef struct game_info
{
    int wins;
    int losses;
    int total_games_played;
} Game_info;

void init_sentences(char sentences[20][48]);
void generate_sentences(char* article[], char* noun[], char* verb[], char* preposition[], char* sentence[]);
void print_board(Cell** board, int size);
int check_win(Cell** board, int size);
void reset_board(Cell** board, int size);
void ai_move(Cell** board, int size, int turn);