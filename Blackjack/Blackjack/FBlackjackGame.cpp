/*
	AUTHOR: Thomas CIANFARANI
	CONTEXT: Blackjack game to consolidate my new C++ skills.
	DESCRIPTION:
	This is the FBlackjackGame class. It is responsible for the game conduct.
*/

#pragma once
#include "FBlackjackGame.h"
#include <iterator>

// Constructor
FBlackjackGame::FBlackjackGame(int32 AmountOfRounds) { Reset(AmountOfRounds); }

// Getters
int32 FBlackjackGame::GetCurrentRound() const { return CurrentRound; }
int32 FBlackjackGame::GetAmountOfRoundsToWin() const { return AmountOfRoundsToWin; }

// Setters
void FBlackjackGame::NextRound() { CurrentRound++; }

// Workers 
void FBlackjackGame::Reset(int32 AmountOfRounds)
{
	CurrentRound = 1;
	AmountOfRoundsToWin = AmountOfRounds;

	// Init cards
	int32 CardIndex = 0;
	AvailableCards = {
		// TODO: Add Aces
		// HEARTS
		{CardIndex++, { "2 of Hearts", 2 }},
		{CardIndex++, { "3 of Hearts", 3 }},
		{CardIndex++, { "4 of Hearts", 4 }},
		{CardIndex++, { "5 of Hearts", 5 }},
		{CardIndex++, { "6 of Hearts", 6 }},
		{CardIndex++, { "7 of Hearts", 7 }},
		{CardIndex++, { "8 of Hearts", 8 }},
		{CardIndex++, { "9 of Hearts", 9 }},
		{CardIndex++, { "10 of Hearts", 10 }},
		{CardIndex++, { "Jack of Hearts", 10 }},
		{CardIndex++, { "Queen of Hearts", 10 }},
		{CardIndex++, { "King of Hearts", 10 }},
		// DIAMONDS
		{CardIndex++, { "2 of Diamonds", 2 }},
		{CardIndex++, { "3 of Diamonds", 3 }},
		{CardIndex++, { "4 of Diamonds", 4 }},
		{CardIndex++, { "5 of Diamonds", 5 }},
		{CardIndex++, { "6 of Diamonds", 6 }},
		{CardIndex++, { "7 of Diamonds", 7 }},
		{CardIndex++, { "8 of Diamonds", 8 }},
		{CardIndex++, { "9 of Diamonds", 9 }},
		{CardIndex++, { "10 of Diamonds", 10 }},
		{CardIndex++, { "Jack of Diamonds", 10 }},
		{CardIndex++, { "Queen of Diamonds", 10 }},
		{CardIndex++, { "King of Diamonds", 10 }},
		// CLUBS
		{CardIndex++, { "2 of Clubs", 2 }},
		{CardIndex++, { "3 of Clubs", 3 }},
		{CardIndex++, { "4 of Clubs", 4 }},
		{CardIndex++, { "5 of Clubs", 5 }},
		{CardIndex++, { "6 of Clubs", 6 }},
		{CardIndex++, { "7 of Clubs", 7 }},
		{CardIndex++, { "8 of Clubs", 8 }},
		{CardIndex++, { "9 of Clubs", 9 }},
		{CardIndex++, { "10 of Clubs", 10 }},
		{CardIndex++, { "Jack of Clubs", 10 }},
		{CardIndex++, { "Queen of Clubs", 10 }},
		{CardIndex++, { "King of Clubs", 10 }},
		// SPADES
		{CardIndex++, { "2 of Spades", 2 }},
		{CardIndex++, { "3 of Spades", 3 }},
		{CardIndex++, { "4 of Spades", 4 }},
		{CardIndex++, { "5 of Spades", 5 }},
		{CardIndex++, { "6 of Spades", 6 }},
		{CardIndex++, { "7 of Spades", 7 }},
		{CardIndex++, { "8 of Spades", 8 }},
		{CardIndex++, { "9 of Spades", 9 }},
		{CardIndex++, { "10 of Spades", 10 }},
		{CardIndex++, { "Jack of Spades", 10 }},
		{CardIndex++, { "Queen of Spades", 10 }},
		{CardIndex++, { "King of Spades", 10 }},
	};
}

// Draws a random card from the available cards and returns
std::pair<std::string, int32> FBlackjackGame::DrawCard()
{
	int32 Random = rand() % AvailableCards.size();
	return AvailableCards[Random];
}