#include "header.h"

void roll_5die(int dice1[5][5], int rollc)
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
	rollc++;
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
			scanf("%d", &answer);

			system("CLS");
		}
		else if (answer == 2) // 2 means start game
		{
			return answer;
		}
		else if (answer == 3) // 3 Means end game
		{
			return answer;
		}
	}
}

int select_reroll(int dice1[5][5], char yn)
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

void frequencyc(int dice1[5][5])
{
	int frequency_table[6] = {0,0,0,0,0,0};
	int index = 0;
	for (int i = 0; i < 5; i++)
	{
		index = dice1[0][i] - 1;
		frequency_table[index]++;
	}

	printf("Ones: %d\n", frequency_table[0]);
	printf("Twos: %d\n", frequency_table[1]);
	printf("Threes: %d\n", frequency_table[2]);
	printf("Fours: %d\n", frequency_table[3]);
	printf("Fives: %d\n", frequency_table[4]);
}