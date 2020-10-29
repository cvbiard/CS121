//	PA5 by: Jake Darrow (:
//	This program emulates the dice game yahtzee

#include "header.h"

int main(void)
{
	//Dice rolls for each player
	int dice1[2][5] = { {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1} };
	int dice2[2][5] = { {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1} };

	//Stores score for each combo posibility
	int score1[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int score2[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	//What turn you got what score
	int score_score1[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int score_score2[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int final_score1 = 0, final_score2 = 0;

	//Checks if you've already used combo
	int stopper1[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int stopper2[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	//Variable used to see if you've exceeded 63 points with lower section
	int lowerc1 = 0;
	int lowerc2 = 0;

	//Godsent
	int frequency_table[6] = {0,0,0,0,0,0};
	int rollc = 2, score_counter1 = 0, score_counter2 = 0;
	//Redundant variable used for trouble shooting that I didn't feel like cleaning up
	int score_tracker1 = 0, score_tracker2 = 0;
	char yn = '\0';
	srand(time(NULL)); //Random based on time

	game_menu(); //Opens game menu
	system("CLS"); //Clears screen
	printf("Ready to roll the dice?\n"); //Asks user1 if ready to roll dice
	system("pause"); //Press enter to continue
	system("CLS"); //Clears screen
	
	//14 rounds for 2 players
	for (int i = 0; i < 13; i++)
	{
		//Player 1		Player 1		Player 1		Player 1		Player 1
		printf("Player 1\n");
		roll_5die(dice1); //Rolls Dice
		frequencyc(dice1, frequency_table); //Lists frequencies of dice rolls
		present_options(frequency_table, dice1, score1); // Displays combos that will earn points
		printf("Player 1\n");
		printf("Would you like to lock in your roll? y/n\n");
		scanf("%c%*c", &yn);
		score_tracker1 = select_combo(frequency_table, dice1, yn, score_counter1, rollc, stopper1, lowerc1); //asks player if they want to store, if yes then scans score number, if no then rerolls
		while (yn == 'n')
		{
			while (rollc < 4)
			{
				printf("This is Roll: %d\n", rollc);
				select_reroll(dice1, yn); //asks user if they want to reroll dice one by one
				roll_5die(dice1); //rolls dice
				frequencyc(dice1, frequency_table); //Lists frequencies of dice rolls
				present_options(frequency_table, dice1, score1); // Displays combos that will earn points
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
		printf("score of round %d is: %d\n", i+1, score_score1[i]);
		system("pause");

		//Player 2		Player 2		Player 2		Player 2		Player 2
		printf("Player 2\n");
		roll_5die(dice2); //Rolls Dice
		frequencyc(dice2, frequency_table); //Lists frequencies of dice rolls
		present_options(frequency_table, dice2, score2); // Displays combos that will earn points
		printf("Player 2\n");
		printf("Would you like to lock in your roll? y/n\n");
		scanf("%c%*c", &yn);
		score_tracker2 = select_combo(frequency_table, dice2, yn, score_counter1, rollc, stopper2, lowerc2); //asks player if they want to store, if yes then scans score number, if no then rerolls
		while (yn == 'n')
		{
			while (rollc < 4)
			{
				printf("Player 2\n");
				printf("This is Roll: %d\n", rollc);
				select_reroll(dice2, yn); //asks user if they want to reroll dice one by one
				roll_5die(dice2); //rolls dice
				frequencyc(dice2, frequency_table); //Lists frequencies of dice rolls
				present_options(frequency_table, dice2, score2); // Displays combos that will earn points
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
	printf("Final score for player 1 is: %d\nFinal score for player 2 is: %d\n", final_score1, final_score2);

	return 0;
}