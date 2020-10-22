#include "header.h"

int main(void)
{
	int dice[5][5] = { {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1} };
	srand((unsigned int)time(NULL));

	printf("Ready to roll the dice?");
	system("PAUSE");
	roll_die(dice);
	return 0;
}