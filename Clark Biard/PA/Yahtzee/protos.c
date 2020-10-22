#include "header.h"

void roll_die(int dice[5][5])
{
	int i, die = 0, val = 0;
	for (i = 0; i < 5; i++)
	{
		val = dice[1][i];
		if (val == 1)
		{
			dice[0][i] = (rand() % 6 + 1);
			die = dice[0][i];
			printf("you rolled a %d\n", die);
		}
	}
}