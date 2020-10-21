#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void print_game_rules(void);

double get_bank_balance(void);

int roll_die(void);

int sum_dice(int die1, int die2);

double get_wager_amount(void);

int check_wager_amount(double wager, double balance);

int is_win_loss_or_point(int sum_dice);

int is_point_loss_or_neither(int sum_dice, int point_value);

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);