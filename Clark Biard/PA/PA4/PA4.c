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
void phrase_picker(int state)
{
	int randn;
	if (state == 0)
	{
		randn = rand() % 3;
		if (randn == 0)
		{
			printf("You can't play with no funds, this is a betting game you know!\n");
		}
		if (randn == 1)
		{
			printf("Come on, don't be shy, how much you got in there?\n");
		}
		if (randn == 2)
		{
			printf("Got any dough? You need to put something in the casino account!\n");
		}
	}
	if (state == 1)
	{
		randn = rand() % 3;
		if (randn == 0)
		{
			printf("Go big or go home, that's what my momma always told me!\n");
		}
		if (randn == 1)
		{
			printf("Come on, lets not be stingy.\n");
		}
		if (randn == 2)
		{
			printf("Lemme see some numbers that would make Bond proud!\n");
		}
	}
	if (state == 2)
	{
		randn = rand() % 3;
		if (randn == 0)
		{
			printf("C'mon, roll big!\n");
		}
		if (randn == 1)
		{
			printf("Blow on them for good luck!\n");
		}
		if (randn == 2)
		{
			printf("I hope you're wearing your lucky socks!\n");
		}
	}
	if (state == 3)
	{
		randn = rand() % 3;
		if (randn == 0)
		{
			printf("Nice rolling!\n");
		}
		if (randn == 1)
		{
			printf("What a win, congrats!\n");
		}
		if (randn == 2)
		{
			printf("Now that you're loaded from that victory, lets go again and bet big!\n");
		}
	}
	if (state == 4)
	{
		randn = rand() % 3;
		if (randn == 0)
		{
			printf("Awe, better luck next time.\n");
		}
		if (randn == 1)
		{
			printf("Have you tried not washing you lucky sock? Some say a wash gets rid of the luck\n");
		}
		if (randn == 2)
		{
			printf("Good try, but there's no way you lose twice in a row right? Lets go again!\n");
		}
	}
	if (state == 5)
	{
		randn = rand() % 3;
		if (randn == 0)
		{
			printf("Time to make your point, lets see what you're made of!\n");
		}
		if (randn == 1)
		{
			printf("Going for point now, this is intense!\n");
		}
		if (randn == 2)
		{
			printf("You need to make your point, don't lose those nerves of steel now!\n");
		}
	}
	if (state == 6)
	{
		randn = rand() % 3;
		if (randn == 0)
		{
			printf("Thanks for playing! Your funds will be deposited back into your bank account after 1-10000000 business days.\n");
		}
		if (randn == 1)
		{
			printf("Going so soon? Well, you're welcome back any time.\n");
		}
		if (randn == 2)
		{
			printf("Quitting while you're ahead I see, smart!\n");
		}
	}
}
