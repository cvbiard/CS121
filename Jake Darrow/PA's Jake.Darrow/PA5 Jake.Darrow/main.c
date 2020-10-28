#include "header.h"

int main(void)
{
	int dice1[5][5] = { {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1} };
	int rollc = 1, score1 = 0, score2 = 0;
	char yn = '\0';
	srand(time(NULL));

	game_menu();

	printf("Ready to roll the dice?\n");
	system("PAUSE");
	roll_5die(dice1);
	select_reroll(dice1, yn);
	roll_5die(dice1);
	frequencyc(dice1);

	

	return 0;
}