/*
	AUTHOR: Thomas CIANFARANI
	CONTEXT: Blackjack game to consolidate my new C++ skills.
	DESCRIPTION:
	This is the FPlayer class. It is responsible for the players actions and cards.
*/

#pragma once
#include "FPlayer.h"

// Constructor
FPlayer::FPlayer(std::string Name, PlayerType Type) { CompleteReset(Name, Type); }

// Getters
int32 FPlayer::GetRoundsWonAmount() const { return RoundsWonAmount; }
int32 FPlayer::GetPlayerValue() const { return PlayerValue; }
bool FPlayer::HasEndedRound() const { return RoundEnded; }
std::string FPlayer::GetPlayerName() const { return Name; }
PlayerType FPlayer::GetPlayerType() const { return Type; }

// Setters
void FPlayer::WinRound() { RoundsWonAmount++; }
void FPlayer::AddCard(std::pair<std::string, int32> Card)
{
	PlayerValue += Card.second;
	Cards.insert(Card);
}
void FPlayer::EndRound() { RoundEnded = true; }

// Workers
void FPlayer::CompleteReset(std::string Name, PlayerType Type) // Resets player completly
{
	this->Name = Name;
	this->Type = Type;
	RoundsWonAmount = 0;
	PlayerValue = 0;
	RoundEnded = false;
	Cards.clear();
}

void FPlayer::RoundReset() // Resets player's round values
{
	PlayerValue = 0;
	RoundEnded = false;
	Cards.clear();
}
