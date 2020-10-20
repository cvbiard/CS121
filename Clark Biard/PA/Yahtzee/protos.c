#include "header.h"

void roll_die(int *dice[5][5])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (dice[2][i] == 1)
		{
			dice[1][i] = (rand() % 6 + 1);
		}
	}
}