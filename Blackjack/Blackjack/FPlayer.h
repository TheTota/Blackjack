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

enum class PlayerType
{
	Human,
	AI
};

class FPlayer
{
public:
	FPlayer(std::string, PlayerType);
	
	// Getters
	int32 GetRoundsWonAmount() const;
	int32 GetPlayerValue() const;
	bool PlayerHasEndedRound() const;
	std::string GetPlayerName() const;
	PlayerType GetPlayerType() const;
	// Setters
	void WinRound();
	void AddCard(std::pair<std::string, int32>);
	void EndTurn();
	// Workers
	void Reset(std::string, PlayerType);

private:
	std::string Name;
	PlayerType Type;
	TMap<std::string, int32> Cards;
	int32 RoundsWonAmount;
	int32 PlayerValue;
	bool HasEndedRound;
};
