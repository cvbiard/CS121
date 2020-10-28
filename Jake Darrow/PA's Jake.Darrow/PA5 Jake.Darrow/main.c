#include "header.h"

int main(void)
{
	int dice1[2][5] = { {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1} };
	int frequency_table[6] = { 0,0,0,0,0,0 };
	int rollc = 1, score1 = 0, score2 = 0;
	char yn = '\0';
	srand(time(NULL));
	game_menu();
	system("CLS");
	printf("Ready to roll the dice?\n");
	system("pause");
	system("CLS");
	roll_5die(dice1);
	select_reroll(dice1, yn);
	roll_5die(dice1);
	frequencyc(dice1, frequency_table);
	present_options(frequency_table);

	

	return 0;
}