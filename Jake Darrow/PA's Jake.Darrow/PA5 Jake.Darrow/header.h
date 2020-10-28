#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void roll_5die(int dice1[2][5]);

int game_menu();

int select_reroll(int dice1[2][5], char yn);

void frequencyc(int dice1[2][5], int frequency_table[6]);

void present_options(int frequency_table[6]);