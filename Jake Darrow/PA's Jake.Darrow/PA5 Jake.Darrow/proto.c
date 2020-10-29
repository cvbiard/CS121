#include "header.h"

void roll_5die(int dice1[2][5], int rollc)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (dice1[1][i] == 1)
		{
			dice1[0][i] = (rand() % 6 + 1);
			printf("You rolled a: %d\n ", dice1[0][i]);
		}
		if (dice1[1][i] == 0)
		{
			printf("Die %d stayed as a: %d\n ", i+1, dice1[0][i]);
		}
	}
	
	//print out array values
;
}

int game_menu()
{
	int answer = 0;

	while (answer == 0) //big loop is exited if user wants to start game or exit, menu can be reaccessed if user requests rules
	{
		printf("Welcome to Jake's game of Yahtzee (:\nEnter the number associated with the action you'd like to take\n1. Print Game Rules\n2. Start a Game of Yahtzee\n3. Exit\n");
		scanf("%d%*c", &answer);

		while (answer != 1 && answer != 2 && answer != 3)
		{
			printf("Please enter either 1, 2, or 3 to respond to the previous prompt\n"); //Saftey Check while loop to make sure only valid answers are provided
			scanf("%d%*c", &answer);
		}

		if (answer == 1) //Rules
		{
			system("CLS");

			printf("The scorecard used for Yahtzee is composed of two sections.\nAn upper section and a lower section.\nA total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\nThe upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\nIf a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\nOnce a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\nIf the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus.\nThe lower section contains a number of poker like combinations.\n\n");
			printf("Name					Combo									Score\n");
			printf("3-of-a-kind				Three Dice with the Same Face			Sum of all Face Values on the 5 Dice\n");
			printf("4-of-a-kind				Four Dice with the Same Face			Sum of all Face Values on the 5 Dice\n");
			printf("Full House				One Pair and Three of a Kind			25\n");
			printf("Small Straight			A Sequence of Four Dice					30\n");
			printf("Large Straight			A Sequence of Five Dice					40\n");
			printf("Yahtzee(5-of-a-Kind)	Five dice with the Same Face			50\n");
			printf("Chance					May be used with any sequence of dice	Sum of all Face Values on the 5 Dice\n\n");
			printf("Enter 0 to return to the main menu\n");
			scanf("%d%*c", &answer);

			system("CLS");
		}
		else if (answer == 2) // 2 means start game
		{
			return answer;
		}
		else if (answer == 3) // 3 Means end game
		{
			exit(0);
		}
	}
}

int select_reroll(int dice1[2][5], char yn)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("Die %d is a %d would you like to re-roll that die?\n", i+1, dice1[0][i]);
		scanf("%c%*c", &yn);
		if (yn == 'y')
		{
			dice1[1][i] = 1;
		}
		if (yn == 'n')
		{
			dice1[1][i] = 0;
		}
	}
}

void frequencyc(int dice1[2][5], int frequency_table[6])
{
	for (int j = 0; j < 6; j++)
	{
		frequency_table[j] = 0;
	}

	printf("\n\nCombo Table:\n");
	int index = 0;
	for (int i = 0; i < 5; i++)
	{
		index = dice1[0][i] - 1;
		frequency_table[index]++;
	}

	/*printf("Ones: %d\n", frequency_table[0]);
	printf("Twos: %d\n", frequency_table[1]);
	printf("Threes: %d\n", frequency_table[2]);
	printf("Fours: %d\n", frequency_table[3]);
	printf("Fives: %d\n", frequency_table[4]);
	printf("Sixes: %d\n\n", frequency_table[5]);*/
}

void present_options(int frequency_table[6], int dice1[2][5], int score1[13])
{
	//1. Sum of 1's
	score1[0] = frequency_table[0];
	printf("1. If not already selected, you may choose to call your roll a sum of 1's\nand earn a score equal to: %d\n", score1[0]);

	//2. Sum of 2's
	score1[1] = frequency_table[1]*2;
	printf("2. If not already selected, you may choose to call your roll a sum of 2's\nand earn a score equal to: %d\n", score1[1]);

	//3. Sum of 3's
	score1[2] = frequency_table[2]*3;
	printf("3. If not already selected, you may choose to call your roll a sum of 3's\nand earn a score equal to: %d\n", score1[2]);

	//4. Sum of 4's
	score1[3] = frequency_table[3]*4;
	printf("4. If not already selected, you may choose to call your roll a sum of 4's\nand earn a score equal to: %d\n", score1[3]);

	//5. Sum of 5's
	score1[4] = frequency_table[4]*5;
	printf("5. If not already selected, you may choose to call your roll a sum of 5's\nand earn a score equal to: %d\n", score1[4]);

	//6. Sum of 6's
	score1[5] = frequency_table[5]*6;
	printf("6. If not already selected, you may choose to call your roll a sum of 6's\nand earn a score equal to: %d\n", score1[5]);

	//7. Three of a kind
	if (((frequency_table[0] == 3 || frequency_table[1] == 3) || (frequency_table[2] == 3 || frequency_table[3] == 3)) || frequency_table[4] == 3)
	{
		score1[6] = frequency_table[0] + (frequency_table[1] * 2) + (frequency_table[2] * 3) + (frequency_table[3] * 4) + (frequency_table[4] * 5) + (frequency_table[5] * 6);
		printf("7. If not already selected, you may choose to call your roll a Three-of-a-kind\nand earn a score equal to: %d\n", score1[6]);
	}

	//8. Four of a kind
	if (((frequency_table[0] == 4 || frequency_table[1] == 4) || (frequency_table[2] == 4 || frequency_table[3] == 4)) || frequency_table[4] == 4)
	{
		score1[7] = frequency_table[0] + (frequency_table[1] * 2) + (frequency_table[2] * 3) + (frequency_table[3] * 4) + (frequency_table[4] * 5) + (frequency_table[5] * 6);
		printf("8. If not already selected, you may choose to call your roll a Four-of-a-kind\nand earn a score equal to: %d\n", score1[7]);
	}

	//9. Full House, two pairs and a set of three....None of the frequency values can equal 1
	if (((frequency_table[0] != 1 && frequency_table[1] != 1) && (frequency_table[2] != 1 && frequency_table[3] != 1)) && (frequency_table[4] != 1 && frequency_table[5] != 1))
	{
		score1[8] = 25;
		printf("9. If not already selected, you may choose to call your roll a Full House\nand earn a score of 25 points\n");
	}

	//10. Small Straight, Four die in a series
	if (((frequency_table[0] >= 1 && frequency_table[1] >= 1) && (frequency_table[2] >= 1 && frequency_table[3] >= 1)) ||
		((frequency_table[1] >= 1 && frequency_table[2] >= 1) && (frequency_table[3] >= 1 && frequency_table[4])) ||
		((frequency_table[2] >= 1 && frequency_table[3] >= 1) && (frequency_table[4] >= 1 && frequency_table[5] >= 1)))
	{
		score1[9] = 30;
		printf("10. If not already selected, you may choose to call your roll a Small Straight\nand earn a score of 30 points\n");
	}

	//11. Large Straight, Five die in a series
	if ((((frequency_table[0] == 1 && frequency_table[1] == 1) && (frequency_table[2] == 1 && frequency_table[3] == 1)) && frequency_table[4] == 1) ||
		(((frequency_table[1] == 1 && frequency_table[2] == 1) && (frequency_table[3] == 1 && frequency_table[4] == 1)) && frequency_table[5] == 1))
	{
		score1[10] = 40;
		printf("11. If not already selected, you may choose to call your roll a Large Straight\nand earn a score of 40 points\n");
	}

	//12. Yahtzee, all five die have same face
	if (((frequency_table[0] == 5 || frequency_table[1] == 5 )|| (frequency_table[2] == 5 || frequency_table[3] == 5)) || frequency_table[4] == 5)
	{
		score1[11] = 50;
		printf("!!YAHTZEE!!\nIf not already selected, you may choose to call your roll a Yahtzee\nand earn a score of 50\n");
	}

	//13. Chance
	score1[12] = frequency_table[0] + (frequency_table[1] * 2) + (frequency_table[2] * 3) + (frequency_table[3] * 4) + (frequency_table[4] * 5) + (frequency_table[5] * 6);
	printf("13. If not already selected, you may choose to call your roll Chance\nand earn a score of: %d\n", score1[12]);

	printf("\n\n");
}

int select_combo(int frequency_table[6], int dice1[2][5], char yn, int score_counter, int rollc, int stopper1[13], int lowerc)
{
	int stupidv = 0;
	if (yn == 'y')
	{
		printf("Please enter the number corresponding to the combo you'd like to lock in\n");
		scanf("%d%*c", &score_counter);
		if (stopper1[score_counter] == 0)
		{
			printf("1.%d%*c\n", score_counter);
			stopper1[score_counter] = 1;
			return score_counter - 1;
		}
		if (stopper1[score_counter] == 1)
		{
			while (stupidv == 0)
			{
				printf("That combo has already been used, please enter a different combo");
				scanf("%d%*c", &score_counter);
				if (stopper1[score_counter] == 0)
				{
					printf("1.%d%*c\n", score_counter);
					stopper1[score_counter] = 1;
					return score_counter - 1;
					stupidv = 1;
				}
			}
		}
	}
	else
	{
		yn == 'n';
	}
}