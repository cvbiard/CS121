#include "PA4.h"

void print_rules(void)
{
	printf("Welcome to Craps!\nRules:\n");
	printf("A player rolls two dice. Each die has six faces.\nThese faces contain 1, 2, 3, 4, 5, and 6 spots.\nAfter the dice have come to rest, the sum of the spots on the two upward faces is calculated.\nIf the sum is 7 or 11 on the first throw, the player wins.\nIf the sum is 2, 3, or 12 on the first throw (called 'craps'), the player loses (i.e. the 'house' wins).\nIf the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's 'point.'\nTo win, you must continue rolling the dice until you 'make your point.'\nThe player loses by rolling a 7 before making the point.\n\n");
}
int roll_die(void)
{
	return (rand() % 6 + 1);
}
int sum_dice(int dice1, int dice2)
{
	return (dice1 + dice2);
}
double get_bank_balance(void)
{
	double balance = 0.0;
	printf("Please enter how much money you would like to start with in your bank account\n");
	scanf("%lf%*c", &balance);
	return balance;
}
double get_wager(void)
{
	double wager = 0.0;
	printf("Please enter how much money you would like to wager\n");
	scanf("%lf%*c", &wager);
	return wager;
}
int check_wager_amount(double balance, double wager)
{
	if (balance >= wager)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int is_win_loss_or_point(int sum_dice)
{
	if (sum_dice == 7 || sum_dice == 11)
	{
		return 1;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
int is_point_loss_or_neither(int sum_dice, int point)
{
	if (sum_dice == point)
	{
		return 1;
	}
	else if (sum_dice == 7)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
	if (add_or_subtract == 1)
	{
		return (bank_balance + wager_amount);
	}
	else if (add_or_subtract == 0)
	{
		return(bank_balance - wager_amount);
	}
	else
	{
		return bank_balance;
	}
}
