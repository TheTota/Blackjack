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
	
	int32 GetRoundsWonAmount();
	int32 GetPlayerValue();
	bool PlayerHasEndedTurn();

	void EndTurn();
	void DrawCard(); // TODO: Richer return value

private:
	int32 RoundsWonAmount;
	int32 PlayerValue;
	bool HasEndedTurn;
};

