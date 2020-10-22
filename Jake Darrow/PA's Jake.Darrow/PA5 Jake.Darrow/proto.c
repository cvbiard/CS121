#include "header.h"

void roll_die(int *dice[5][5])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (dice[2][i] == 1)
		{
			dice[1][i] = (rand() % 6 + 1);
			printf("Rolled a: %d", dice[1][i]);
		}
	}
}

void game_menu()
{
	int answer = 1;

	while (answer != 1 || answer != 2 || answer != 3)
	{
		printf("Welcome to Jake's game of Yahtzee (:\nEnter the number associated with the action you'd like to take\n1. Print Game Rules\n2. Start a Game of Yahtzee\n3. Exit\n");
		scanf("%d%*c", &answer);

	}
	
	while (answer == 1)
	{
		printf("The scorecard used for Yahtzee is composed of two sections.\nAn upper section and a lower section.\nA total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\nThe upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\nIf a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\nOnce a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\nIf the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus.\nThe lower section contains a number of poker like combinations.\n\n");
		printf("Name					Combo									Score\n");
		printf("3-of-a-kind				Three Dice with the Same Face			Sum of all Face Values on the 5 Dice\n");
		printf("4-of-a-kind				Four Dice with the Same Face			Sum of all Face Values on the 5 Dice\n");
		printf("Full House				One Pair and Three of a Kind			25\n");
		printf("Small Straight			A Sequence of Four Dice					30\n");
		printf("Large Straight			A Sequence of Five Dice					40\n");
		printf("Yahtzee(5-of-a-Kind)	Five dice with the Same Face			50\n");
		printf("Chance					May be used with any sequence of dice	Sum of all Face Values on the 5 Dice\n\n");
		printf("If you would like to return to the main menu please enter 0\n");
		scanf("%d", &answer);
		return 1;

	}
	if (answer == 2)
	{
		return 2;
	}
	else if (answer == 3);
	{
		return 3;
	}
}