// Authors: Deitel & Deitel - C How to Program

#include "header.h"



int main(void)
{
	struct card AceH = { INIT_CARD };
	struct card AceD = { INIT_CARD };
	struct card AceC = { INIT_CARD };
	struct card AceS = { INIT_CARD };

	struct card TwoH = { INIT_CARD };
	struct card TwoD = { INIT_CARD };
	struct card TwoC = { INIT_CARD };
	struct card TwoS = { INIT_CARD };

	struct card ThreeH = { INIT_CARD };
	struct card ThreeD = { INIT_CARD };
	struct card ThreeC = { INIT_CARD };
	struct card ThreeS = { INIT_CARD };

	struct card FourH = { INIT_CARD };
	struct card FourD = { INIT_CARD };
	struct card FourC = { INIT_CARD };
	struct card FourS = { INIT_CARD };

	struct card FiveH = { INIT_CARD };
	struct card FiveD = { INIT_CARD };;
	struct card FiveC = { INIT_CARD };
	struct card FiveS = { INIT_CARD };


	struct card SixH = { INIT_CARD };
	struct card SixD = { INIT_CARD };
	struct card SixC = { INIT_CARD };
	struct card SixS = { INIT_CARD };

	struct card SevenH = { INIT_CARD };
	struct card SevenD = { INIT_CARD };
	struct card SevenC = { INIT_CARD };
	struct card SevenS = { INIT_CARD };

	struct card EightH = { INIT_CARD };
	struct card EightD = { INIT_CARD };
	struct card EightC = { INIT_CARD };
	struct card EightS = { INIT_CARD };

	struct card NineH = { INIT_CARD };
	struct card NineD = { INIT_CARD };
	struct card NineC = { INIT_CARD };
	struct card NineS = { INIT_CARD };

	struct card TenH = { INIT_CARD };
	struct card TenD = { INIT_CARD };
	struct card TenC = { INIT_CARD };
	struct card TenS = { INIT_CARD };

	struct card JackH = { INIT_CARD };
	struct card JackD = { INIT_CARD };
	struct card JackC = { INIT_CARD };
	struct card JackS = { INIT_CARD };

	struct card QueenH = { INIT_CARD };
	struct card QueenD = { INIT_CARD };
	struct card QueenC = { INIT_CARD };
	struct card QueenS = { INIT_CARD };

	struct card KingH = { INIT_CARD };
	struct card KingD = { INIT_CARD };
	struct card KingC = { INIT_CARD };
	struct card KingS = { INIT_CARD };

	struct card dummy = { INIT_CARD };

	struct card cards[52] = {AceH, AceD, AceC, AceS, TwoH, TwoD, TwoC, TwoS, ThreeH, ThreeD, ThreeC, ThreeS, FourH, FourD, FourC, FourS, FiveH, FiveD, FiveC, FiveS, SixH, SixD, SixC, SixS, SevenH, SevenD, SevenC, SevenS, EightH, EightD, EightC, EightS, NineH, NineD, NineC, NineS, TenH, TenD, TenC, TenS, JackH, JackD, JackC, JackS, QueenH, QueenD, QueenC, QueenS, KingH, KingD, KingC, KingS};

	
	srand((unsigned)time(NULL)); /* seed random-number generator */

	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	int deckpos = 0;
	int winnervar = 0;
	/* initalize deck array */

	int bank1 = 5000;
	int bank2 = 5000;
	int pot[1] = { 0 };
	int first = 0;
	int exit = 0;
	int prevbet = -1;

	int combos1[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int combos2[10] = { 0,0,0,0,0,0,0,0,0,0 };


	char again = '\0';

	srand((time(NULL)));
	init_cards(cards, face, suit);
	//print_cards(cards);
	
	
	
	while (exit != 1)
	{
		int fold[1] = { 0 };
		int fold2[1] = { 0 };
		struct card deck[52] = { dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy };
		struct card hand1[5] = { dummy, dummy, dummy, dummy, dummy };
		struct card hand2[5] = { dummy, dummy, dummy, dummy, dummy };

		struct card highest1[1] = { dummy };
		struct card highest2[1] = { dummy };

		printf("You need to ante up, putting $100 in the pot from both players.\n");
		system("PAUSE");
		system("cls");
		pot[0] = 200;
		bank1 = bank1 - 100;
		bank2 = bank2 - 100;
		printf("The pot is $%d\n", pot[0]);
		printf("Flipping a coin to see who goes first.\n");
		system("PAUSE");
		system("cls");
		first = rand() % 2;
		printf("Player %d goes first\n", first + 1);
		system("PAUSE");
		system("cls");
		shuffle(deck, cards);	
		if (first == 0)
		{
			deckpos = deal(deck, hand1, dummy, deckpos);
			print_hand(hand1);
			printf("\n");
			deckpos = deal(deck, hand2, dummy, deckpos);

			determiner(hand1, combos1, 0);
			bank1 = move(bank1, pot, -1, fold);
			if (fold[0] == 0)
			{
				printf("The pot is $%d\n", pot[0]);
				print_hand(hand1);
				get_replace(hand1);

				determiner(hand2, combos2, 1);
				prevbet = ai_bet(bank2, pot, combos2, fold, fold2);
				printf("The pot is $%d\n", pot[0]);
				eval(hand2, combos2, highest2);

				deckpos = deal(deck, hand1, dummy, deckpos);
				print_hand(hand1);
				printf("\n");
				deckpos = deal(deck, hand2, dummy, deckpos);


				determiner(hand1, combos1, 0);
				bank1 = move(bank1, pot, prevbet, fold);
				if (fold[0] == 0)
				{
					printf("The pot is $%d\n", pot[0]);
					eval(hand1, combos1, highest1);

					determiner(hand2, combos2, 1);
					prevbet = ai_bet(bank2, pot, combos2, fold, fold2);
					printf("The pot is $%d\n", pot[0]);
					eval(hand2, combos2, highest2);
				}
			}
		}
		else if (first == 1)
		{
			deckpos = deal(deck, hand2, dummy, deckpos);

			deckpos = deal(deck, hand1, dummy, deckpos);
			print_hand(hand1);
			printf("\n");
			printf("Your opponent is taking their turn.\n");
			system("PAUSE");
			system("cls");

			determiner(hand2, combos2, 1);
			prevbet = ai_bet(bank2, pot, combos2, fold, fold2);
			system("PAUSE");
			system("cls");
			printf("The pot is $%d\n", pot[0]);
			eval(hand2, combos2, highest2);

			print_hand(hand1);
			printf("\n");
			determiner(hand1, combos1, 0);
			bank1 = move(bank1, pot, prevbet, fold);
			if (fold == 0)
			{
				printf("The pot is $%d\n", pot[0]);
				print_hand(hand1);
				get_replace(hand1);

				deckpos = deal(deck, hand2, dummy, deckpos);

				deckpos = deal(deck, hand1, dummy, deckpos);
				print_hand(hand1);
				printf("\n");

				determiner(hand2, combos2, 1);
				prevbet = ai_bet(bank2, pot, combos2, fold, fold2);
				printf("The pot is $%d\n", pot[0]);
				eval(hand2, combos2, highest2);

				determiner(hand1, combos1, 0);
				bank1 = move(bank1, pot, prevbet, fold);
				if (fold[0] == 0)
				{
					printf("The pot is $%d\n", pot[0]);
					eval(hand1, combos1, highest1);
				}
			}			
		}
		winnervar = winner_check(hand1, hand2, combos1, combos2, highest1, highest2);
		print_hand(hand2);
		if (fold[0] == 1)
		{
			if (fold2[0] == 0)
			{
				winnervar = 1;
			}
			else
			{
				winnervar = 0;
			}
		}
		if (winnervar == 0)
		{
			printf("You won\n");
			bank1 = bank1 + pot[0];
			pot[0] = 0;
		}
		else
		{
			printf("AI won\n");
			bank2 = bank2 + pot[0];
			pot[0] = 0;
		}
		printf("Would you like to go again? Enter 'y' for yes or 'n' for no.\n");
		scanf("%c%*c", &again);
		if (again == 'n')
		{
			exit = 1;
		}
		system("cls");
	}
	return 0;
}
