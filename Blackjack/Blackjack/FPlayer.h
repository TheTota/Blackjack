/*
	AUTHOR: Thomas CIANFARANI
	CONTEXT: Blackjack game to consolidate my new C++ skills.
	DESCRIPTION:
	This is the header file for the FPlayer class.
*/

#pragma once
#include <string>
#include <map>
#define TMap std::map
using int32 = int;

class FPlayer
{
public:
	FPlayer(std::string);
	
	// Getters
	int32 GetRoundsWonAmount();
	int32 GetPlayerValue();
	bool PlayerHasEndedRound();
	std::string GetPlayerName();
	// Setters
	void WinRound();
	void AddCard(std::pair<std::string, int32>);
	void EndTurn();
	// Workers
	void Reset(std::string);

private:
	std::string Name;
	TMap<std::string, int32> Cards;
	int32 RoundsWonAmount;
	int32 PlayerValue;
	bool HasEndedRound;
};

