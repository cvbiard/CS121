// Authors: Deitel & Deitel - C How to Program

#include "header.h"

int main(void)
{
	struct card AceH = {INIT_CARD};
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
	/* initalize deck array */
	struct card deck[52] = { dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy };
	struct card hand1[5] = { dummy, dummy, dummy, dummy, dummy };
	struct card hand2[5] = { dummy, dummy, dummy, dummy, dummy };
	init_cards(cards, face, suit);
	print_cards(cards);
	shuffle(deck, cards);
	deal(deck, hand1, dummy, deckpos);

	return 0;
}
