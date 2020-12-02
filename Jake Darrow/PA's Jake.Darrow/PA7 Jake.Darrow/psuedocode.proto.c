#include "header.h"

// DEAL CARDS--After deck is shuffled five cards need to be dealt to player and to computer

//TURN CHOOSER--randomly decides if player or cpu goes first

//ANTE UP--Everyone needs to ante certain amount(wiki says $1), otherwise there is no penalty for folding on first round
//{
//	prompts player to enter $5 ante
//	system pause for player interaction
//	updates players wallet by removing $5 and updates pot adding $5
//}

//BETTING ROUND--players bet on whether their hand will win. Player will be shown their hand then prompted to either
//call, raise fold, or all in. There needs to be safety check to make sure answer is only one of those, if answer is raise then player must then 
//input how much more in increments of 5
//CPU will randomly choose fold, call, or raise, or all in, and randomly choose amount to raise between set amount. Need to figure way to weight
//CPU options becuase game will be annoying if CPU chooses to go all in or fold as often as they call
//IF someone folds then round is over
//After bets are set they needed to be added to the pot.
//amount for Call needs to be updated after each bet
//Amount anyone can raise has to be restrained by how much money they have left. Cannot raise to then bet more than you have.

//CHOOSE BET MOVE
//{
//	prompts player to either fold, call, raise, or go all in
//	while loop runs to safety check that only one of the options is picked
//}

//DRAW