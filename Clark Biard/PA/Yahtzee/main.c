#include "header.h"

int main(void)
{
	int dice[5][5] = { {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1} };
	int i;
	char yn = '\0';
	srand((unsigned int)time(NULL));

	printf("Ready to roll the dice?\n");
	system("PAUSE");
	roll_die(dice);
	determiner(dice);

	for (i = 0; i < 5; i++)
	{
		printf("Would you like to reroll die %d? Current value %d, y/n\n", i + 1, dice[0][i]);
		scanf("%c%*c", &yn);
		if (yn == 'y')
		{
			dice[1][i] = 1;
		}
		if (yn == 'n')
		{
			dice[1][i] = 0;
		}
	}
	roll_die(dice);


	for (i = 0; i < 5; i++)
	{
		printf("Would you like to reroll die %d? Current value %d, y/n\n", i + 1, dice[0][i]);
		scanf("%c%*c", &yn);
		if (yn == 'y')
		{
			dice[1][i] = 1;
		}
		if (yn == 'n')
		{
			dice[1][i] = 0;
		}
	}
	roll_die(dice);

	return 0;
}