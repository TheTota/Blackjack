/*
	AUTHOR: Thomas CIANFARANI
	CONTEXT: Blackjack game to consolidate my new C++ skills.
	DESCRIPTION:
	This is the FPlayer class. It is responsible for the players actions and cards.
*/

#pragma once
#include "FPlayer.h"

// Constructor
FPlayer::FPlayer() { Reset(); }

// Getters
int32 FPlayer::GetRoundsWonAmount() { return RoundsWonAmount; }
int32 FPlayer::GetPlayerValue() { return PlayerValue; }
bool FPlayer::PlayerHasEndedRound() { return HasEndedRound; }

// Setters
void FPlayer::WinRound() { RoundsWonAmount++; }
void FPlayer::AddCard(std::pair<std::string, int> Card) { Cards.insert(Card); }
void FPlayer::EndTurn() { HasEndedRound = true; }

// Workers
void FPlayer::Reset()
{
	RoundsWonAmount = 0;
	PlayerValue = 0;
	HasEndedRound = false;
	Cards.clear();
}
