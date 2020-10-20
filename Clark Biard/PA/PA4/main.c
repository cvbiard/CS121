#include "PA4.h"


int main(void)
{
	int dice1 = 0, dice2 = 0, point = 0, sum = 0, win = 0, check = 0, c1 = 0, c2 = 0, turn = 0, exit = 0, wlp = 0, pln = 0, turn1 = 0, flush = 0;
	double balance = 0.0, wager = 0.0;
	char cr = '0', c = '0';

	srand((unsigned int)time(NULL));

	while (exit != 1)
	{
		if (turn == 0)
		{
			print_rules();
			balance = get_bank_balance();
			turn = turn + 1;
			turn1 = turn1 + 1;
		}
		else
		{
			if (turn == turn1)
			{
				wager = get_wager();
				check = check_wager_amount(balance, wager);
				while (check != 1)
				{
					printf("You are wagering more than you have! Your current balance is $%.2lf.\n", balance);
					wager = get_wager();
					check = check_wager_amount(balance, wager);
				}
			}
			
			printf("Press enter to roll the dice!\n");
			scanf("%c", &cr);
			//system("cls");
	
			dice1 = roll_die();
			dice2 = roll_die();
			printf("You rolled a %d and %d.\n", dice1, dice2);

			sum = sum_dice(dice1, dice2);
			printf("The sum is %d.\n", sum);

			if (turn == 1)
			{
				wlp = is_win_loss_or_point(sum);
				if (wlp == 0)
				{
					printf("You lose.\n");
					balance = adjust_bank_balance(balance, wager, 0);
					printf("Your new bank balance is $%.2lf.\n", balance);
					turn = 1;
					turn1 = turn;
					printf("Would you like to quit? Enter 1 to quit and 0 to continue.\n");
					scanf("%d%*c", &exit);
					
				}
				else if (wlp == 1)
				{
					printf("You win\n");
					balance = adjust_bank_balance(balance, wager, 1);
					printf("Your new bank balance is $%.2lf.\n", balance);
					turn = 1;
					turn1 = turn;
					printf("Would you like to quit? Enter 1 to quit and 0 to continue.\n");
					scanf("%d%*c", &exit);
					
				}
				else
				{
					point = sum;
					turn = turn + 1;

				}
			}
			else
			{
				pln = is_point_loss_or_neither(sum, point);

				if (pln == 0)
				{
					printf("You lose\n");
					balance = adjust_bank_balance(balance, wager, 0);
					printf("Your new bank balance is $%.2lf.\n", balance);
					turn = 1;
					turn1 = turn;
					printf("Would you like to quit? Enter 1 to quit and 0 to continue.\n");
					scanf("%d%*c", &exit);
					
				}
				else if (pln == 1)
				{
					printf("You win\n");
					balance = adjust_bank_balance(balance, wager, 1);
					printf("Your new bank balance is $%.2lf.\n", balance);
					turn = 1;
					turn1 = turn;
					printf("Would you like to quit? Enter 1 to quit and 0 to continue.\n");
					scanf("%d%*c", &exit);
				
				}
				else
				{
					point = sum;
					turn = turn + 1;

				}
			}
		}
	}
}