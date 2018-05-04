/*
	AUTHOR: Thomas CIANFARANI
	CONTEXT: Blackjack game to consolidate my new C++ skills.
	DESCRIPTION:
	This is the header file for the FPlayer class.
*/

#pragma once
#include <string>
using int32 = int;

class FPlayer
{
public:
	FPlayer();
	
	// Getters
	int32 GetRoundsWonAmount();
	int32 GetPlayerValue();
	bool PlayerHasEndedRound();
	// Setters
	void WinRound();
	// Workers
	void EndTurn();
	void DrawCard(); // TODO: Richer return value
	void Reset();

private:
	int32 RoundsWonAmount;
	int32 PlayerValue;
	bool HasEndedRound;
};

