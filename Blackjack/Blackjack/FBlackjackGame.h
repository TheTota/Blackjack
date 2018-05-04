/*
	AUTHOR: Thomas CIANFARANI
	CONTEXT: Blackjack game to consolidate my new C++ skills.
	DESCRIPTION:
	This is the header file for the FBlackjackGame class.
*/

#pragma once
#include <string>
using int32 = int;

class FBlackjackGame
{
public:
	FBlackjackGame(int32);
	
	// Getters
	int32 GetCurrentRound();
	int32 GetAmountOfRoundsToWin();
	// Setters
	void NextRound();

private:
	int32 CurrentRound;
	int32 AmountOfRoundsToWin;

};

