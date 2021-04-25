#include "header.h"

int main(void)
{
	//Dice rolls for players
	int dice1[2][5] = { {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1} };
	int dice2[2][5] = { {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1} };

	//scores
	int score1[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int score2[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	//What turn each score was gotten
	int score_score1[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int score_score2[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int final_score1 = 0, final_score2 = 0;

	//Checks if combo has been used
	int stopper1[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int stopper2[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	//Variable if you've exceeded 63 in lower section
	int lowerc1 = 0;
	int lowerc2 = 0;

	int frequency_table[6] = { 0,0,0,0,0,0 };
	int rollc = 2, score_counter1 = 0, score_counter2 = 0;
	int score_tracker1 = 0, score_tracker2 = 0;
	char yn = '\0';
	srand(time(NULL)); 

	game_menu();
	system("CLS");
	printf("Ready to roll the dice?\n");
	system("pause");
	system("CLS");

	
	for (int i = 0; i < 13; i++)
	{
		//player 1
		printf("Player 1\n");
		roll_5die(dice1);
		frequencyc(dice1, frequency_table);
		present_options(frequency_table, dice1, score1);
		printf("Player 1\n");
		printf("Would you like to lock in your roll? y/n\n");
		scanf("%c%*c", &yn);
		score_tracker1 = select_combo(frequency_table, dice1, yn, score_counter1, rollc, stopper1, lowerc1);
		while (yn == 'n')
		{
			while (rollc < 4)
			{
				printf("This is Roll: %d\n", rollc);
				select_reroll(dice1, yn); 
				roll_5die(dice1);
				frequencyc(dice1, frequency_table);
				present_options(frequency_table, dice1, score1);
				score_tracker1 = select_combo(frequency_table, dice1, yn, score_counter1, rollc, stopper1, lowerc1);
				rollc++;
			}
			yn = 'y';
			score_tracker1 = select_combo(frequency_table, dice1, yn, score_counter1, rollc, stopper1, lowerc1);
		}
		printf("2.%d\n", score_tracker1);
		printf("3.%d\n", score1[score_tracker1]);
		score_score1[i] = score1[score_tracker1];

		printf("Player 1\n");
		printf("score of round %d is: %d\n", i + 1, score_score1[i]);
		system("pause");

		//Player 2
		printf("Player 2\n");
		roll_5die(dice2);
		frequencyc(dice2, frequency_table);
		present_options(frequency_table, dice2, score2);
		printf("Player 2\n");
		printf("Would you like to lock in your roll? y/n\n");
		scanf("%c%*c", &yn);
		score_tracker2 = select_combo(frequency_table, dice2, yn, score_counter1, rollc, stopper2, lowerc2);
		while (yn == 'n')
		{
			while (rollc < 4)
			{
				printf("Player 2\n");
				printf("This is Roll: %d\n", rollc);
				select_reroll(dice2, yn);
				roll_5die(dice2);
				frequencyc(dice2, frequency_table);
				present_options(frequency_table, dice2, score2);
				score_tracker2 = select_combo(frequency_table, dice2, yn, score_counter2, rollc, stopper2, lowerc2);
				rollc++;
			}
			yn = 'y';
			score_tracker2 = select_combo(frequency_table, dice2, yn, score_counter2, rollc, stopper2, lowerc2);
		}
		printf("Player 2\n");
		printf("2.%d\n", score_tracker2);
		printf("3.%d\n", score1[score_tracker2]);
		score_score2[i] = score1[score_tracker2];

		printf("Player 2\n");
		printf("score of round %d is: %d\n", i + 1, score_score2[i]);
		system("pause");

	}
	for (int i = 0; i < 13; i++)
	{
		final_score1 = final_score1 + score_score1[i];
		final_score2 = final_score2 + score_score2[i];
	}
	lowerc1 = score1[6] + score1[7] + score1[8] + score1[9] + score1[10] + score1[11] + score1[12];
	lowerc2 = score2[6] + score2[7] + score2[8] + score2[9] + score2[10] + score2[11] + score2[12];
	if (lowerc1 >= 63)
	{
		final_score1 = final_score1 + 35;
	}
	if (lowerc2 >= 63)
	{
		final_score2 = final_score2 + 35;
	}
	printf("Final score for player 1 is %d\nFinal score for player 2 is %d\n", final_score1, final_score2);

	return 0;
}