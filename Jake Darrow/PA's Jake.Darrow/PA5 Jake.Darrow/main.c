#include "header.h"

int main(void)
{
	int* dice[5][5] = { {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1} };
	int rollc = 0;
	srand(time(NULL));

	game_menu();

	printf("Ready to roll the dice?\n");
	system("PAUSE");
	roll_die(dice[5][5]);
	return 0;
}