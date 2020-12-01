

// Jake.Darrow PA7 CptS 121
//This program emulates the variant of poker called 5 card draw
// Code from authors: Deitel & Deitel - C How to Program used for shuffle and deal functions

#include "header.h"

int main(void)
{
	struct card AceH = { 0, 0 ,0 };
	struct card AceD = { 0, 0 ,0 };
	struct card AceC = { 0, 0 ,0 };
	struct card AceS = { 0, 0 ,0 };

	struct card TwoH = { 0, 0 ,0 };
	struct card TwoD = { 0, 0 ,0 };
	struct card TwoC = { 0, 0 ,0 };
	struct card TwoS = { 0, 0 ,0 };

	struct card ThreeH = { 0, 0 ,0 };
	struct card ThreeD = { 0, 0 ,0 };
	struct card ThreeC = { 0, 0 ,0 };
	struct card ThreeS = { 0, 0 ,0 };

	struct card FourH = { 0, 0 ,0 };
	struct card FourD = { 0, 0 ,0 };
	struct card FourC = { 0, 0 ,0 };
	struct card FourS = { 0, 0 ,0 };

	struct card FiveH = { 0, 0 ,0 };
	struct card FiveD = { 0, 0 ,0 };
	struct card FiveC = { 0, 0 ,0 };
	struct card FiveS = { 0, 0 ,0 };


	struct card SixH = { 0, 0 ,0 };
	struct card SixD = { 0, 0 ,0 };
	struct card SixC = { 0, 0 ,0 };
	struct card SixS = { 0, 0 ,0 };

	struct card SevenH = { 0, 0 ,0 };
	struct card SevenD = { 0, 0 ,0 };
	struct card SevenC = { 0, 0 ,0 };
	struct card SevenS = { 0, 0 ,0 };

	struct card EightH = { 0, 0 ,0 };
	struct card EightD = { 0, 0 ,0 };
	struct card EightC = { 0, 0 ,0 };
	struct card EightS = { 0, 0 ,0 };

	struct card NineH = { 0, 0 ,0 };
	struct card NineD = { 0, 0 ,0 };
	struct card NineC = { 0, 0 ,0 };
	struct card NineS = { 0, 0 ,0 };

	struct card TenH = { 0, 0 ,0 };
	struct card TenD = { 0, 0 ,0 };
	struct card TenC = { 0, 0 ,0 };
	struct card TenS = { 0, 0 ,0 };

	struct card JackH = { 0, 0 ,0 };
	struct card JackD = { 0, 0 ,0 };
	struct card JackC = { 0, 0 ,0 };
	struct card JackS = { 0, 0 ,0 };

	struct card QueenH = { 0, 0 ,0 };
	struct card QueenD = { 0, 0 ,0 };
	struct card QueenC = { 0, 0 ,0 };
	struct card QueenS = { 0, 0 ,0 };

	struct card KingH = { 0, 0 ,0 };
	struct card KingD = { 0, 0 ,0 };
	struct card KingC = { 0, 0, 0 };
	struct card KingS = { 0, 0, 0 };

	struct card cards[52] = { AceH, AceD, AceC, AceS, TwoH, TwoD, TwoC, TwoS, ThreeH, ThreeD, ThreeC, ThreeS, FourH, FourD, FourC, FourS, FiveH, FiveD, FiveC, FiveS, SixH, SixD, SixC, SixS, SevenH, SevenD, SevenC, SevenS, EightH, EightD, EightC, EightS, NineH, NineD, NineC, NineS, TenH, TenD, TenC, TenS, JackH, JackD, JackC, JackS, QueenH, QueenD, QueenC, QueenS, KingH, KingD, KingC, KingS };

	struct player player1;
	struct player cpu;
	player1.wallet = 0;
	cpu.wallet = 0;

	srand((unsigned)time(NULL)); /* seed random-number generator */

	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };


	/* initalize deck array */
	int deck[4][13] = { 0 };

	//shuffle(deck);
	//deal(deck, face, suit);

	game_menu();
	init_cards(cards);
	print_cards(cards, face, suit);

	return 0;
}