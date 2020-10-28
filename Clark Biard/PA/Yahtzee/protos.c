#include "header.h"

void roll_die(int dice[5][5])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (dice[1][i] == 1)
		{
			dice[0][i] = (rand() % 6 + 1);
			printf("For dice %d, you rolled a %d\n", i+1, dice[0][i]);
		}
		if (dice[1][i] == 0)
		{
			printf("Dice %d stayed at %d\n", i+1, dice[0][i]);
		}
	}
}

int game_menu()
{
	int answer = 0;

	while (answer == 0)
	{
		printf("Please enter the number of what you'd like to do.\n");
		scanf("%d%*c", &answer);

		while (answer != 1 && answer != 2 && answer != 3);
		{
			printf("Please enter a valid option, 1, 2, or 3.\n");
			scanf("%d%*c", &answer);
		}

		if (answer == 1)
		{
			//Rules
		}
		else if (answer == 2)
		{
			//Start game
			return answer;
		}
		else if (answer == 3)
		{
			//End game
			return answer;
		}
	}
}

void determiner(int dice[5][5])
{

	int frequency_table[6] = {0,0,0,0,0,0};
	int index = 0;
	for (int i = 0; i < 5; i++)
	{
		index = dice[0][i] - 1;
		frequency_table[index]++;
	}
	printf("Ones %d\n", frequency_table[0]);
	printf("Twos %d\n", frequency_table[1]);
	printf("Threes %d\n", frequency_table[2]);
	printf("Fours %d\n", frequency_table[3]);
	printf("Fives %d\n", frequency_table[4]);
}