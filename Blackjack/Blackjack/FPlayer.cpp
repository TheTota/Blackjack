/*
	AUTHOR: Thomas CIANFARANI
	CONTEXT: Blackjack game to consolidate my new C++ skills.
	DESCRIPTION:
	This is the FPlayer class. It is responsible for the players actions and cards.
*/

#pragma once
#include "FPlayer.h"

// Constructor
FPlayer::FPlayer()
{
	
}

int32 FPlayer::GetRoundsWonAmount()
{
	return int32();
}

int32 FPlayer::GetPlayerValue()
{
	return int32();
}

bool FPlayer::PlayerHasEndedTurn()
{
	return false;
}

void FPlayer::EndTurn()
{
}

void FPlayer::DrawCard()
{
}
