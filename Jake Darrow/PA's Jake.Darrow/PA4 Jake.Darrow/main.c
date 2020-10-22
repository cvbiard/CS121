//	PA4 CptS 121
//	Program made by: Jake Darrow, in collaboration with Clark Biard
//	5 October 2020
//	This program emulates the game 'Craps'

//enables 3 file organization
#include "header.h"



int main(void)
{
	//Sets random function seed
	srand(time(NULL));

	//Define all integers, doubles, and char
	int die1 = 0, die2 = 0, point = 0, turn = 0, end = 0, tA = 0, tB = 0, wlp = 0, pln = 0, sum = 0, blank = 0;
	double balance = 1.0, wager = 0.0, test = 0.0;
	char Q;

	print_game_rules();

	//The big while loop that just about everything operates in, this while loop exists so that if the condition is made to not be satisfied that the user exits the game
	while (end != 1)
	{
		//Check if player is broke then they cannot play anymore, redfines condition relevant to big while loop
		//I have this block of code at the bottom and the top of the program. Without it at both top/bottom the game doesn't always boot you out when your balance is zero
		if (balance <= 0)
		{
			end = 1;
		}

		//tA is a turn counter, Clark's brilliant idea to use two of these, tA = 0 is reserved for the initial game condition
		if (tA == 0)
		{
			balance = get_bank_balance();

			tA = tA + 1;
			tB = tA;
		}

		//Turn counters start equal to each other so that this portionn can run which prompts user for wager amount
		//if the user rolls the dice and they neither win or lose then they don't need to enter another wager so they skip the block below
		if (tA == tB)
		{
			wager = get_wager_amount();

			test = check_wager_amount(wager, balance);

			//chatter
			if (wager == balance)
			{
				printf("You are a bold one\n");
			}

			//test to make sure user isn't pulling money out of thin air, if the numbers don't add up user is given option to wager new amount
			while (test == 0)
			{
				printf("You can't bet more money than you have ):\n");
				wager = get_wager_amount();
				test = check_wager_amount(wager,balance);
			}
		}
		printf("Press enter to roll dem dice\n");

		//Trick to make game wait for you before rolling dice again
		scanf("%c%c", &Q, &Q);

		die1 = roll_die();
		die2 = roll_die();
		printf("You rolled a %d, and a %d\n", die1, die2);
		sum = sum_dice(die1, die2);
		printf("The sum of your rolls is: %d\n", sum);

		
		//First Roll Operations
		if (tA == 1)
		{
			wlp = is_win_loss_or_point(sum);
			//If win on first roll
			if (wlp == 0 && balance > 0)
			{
				printf("Loser\n");
				balance = adjust_bank_balance(balance, wager, 0);
				tA = 1;
				tB = tA;
				printf("Your current balance is: %.2lf\n", balance);
				printf("If you'd like to call your loss enter 1, if you wanna keep on playing enter 0\n");
				scanf("%d", &end);
			}

			//If lose on first roll
			else if (wlp == 1 && balance > 0)
			{
				printf("Winna\n");
				balance = adjust_bank_balance(balance, wager, 1);
				tA = 1;
				tB = tA;
				printf("Your current balance is: %.2lf\n", balance);
				printf("If you'd like to call it a wrap enter 1, if you wanna keep on playing enter 0\n");
				scanf("%d", &end);
			}

			//If Don't win or lose
			else
			{
				printf("Bad Luck ): \n");
				point = sum;
				tA = tA + 1;
						
			}

		}

		else
		{
			pln = is_point_loss_or_neither(sum, point);


			if (pln == 0 && balance > 0)
			{
				printf("Loser\n");
				balance = adjust_bank_balance(balance, wager, 0);
				tA = 1;
				tB = tA;

				printf("Your current balance is: %.2lf\n", balance);
				printf("If you'd like to call it a wrap enter 1, if you wanna keep on playing enter 0\n");
				scanf("%d", &end);
			}

			else if (pln == 1 && balance > 0)
			{
				printf("Winna\n");
				balance = adjust_bank_balance(balance, wager, 1);
				tA = 1;
				tB = tA;

				printf("Your current balance is: %.2lf\n", balance);
				printf("If you'd like to call it a wrap enter 1, if you wanna keep on playing enter 0\n");
				scanf("%d", &end);
			}

			//If you lose but not game over after first roll
			else
			{
				printf("Bad Luck ): \n");
				point = sum;
				tA = tA +1;
				
			}
		}

		if (balance <= 0)
		{
			end = 1;
		}
		
	}

	printf("game over (:\n");
	return 0;
}