/*
	AUTHOR: Thomas CIANFARANI
	CONTEXT: Blackjack game to consolidate my new C++ skills.
	DESCRIPTION:
	This is the FBlackjackGame class. It is responsible for the game conduct.
*/

#pragma once
#include "FBlackjackGame.h"

// Constructor
FBlackjackGame::FBlackjackGame(int32 AmountOfRounds)
{
	CurrentRound = 1;
	AmountOfRoundsToWin = AmountOfRounds;
}

int32 FBlackjackGame::GetCurrentRound()
{
	return CurrentRound;
}

int32 FBlackjackGame::GetAmountOfRoundsToWin()
{
	return AmountOfRoundsToWin;
}

void FBlackjackGame::NextRound()
{
	CurrentRound++;
}
