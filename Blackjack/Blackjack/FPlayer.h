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

enum class PlayerAction
{
	Hit,
	Stand
};

class FPlayer
{
public:
	FPlayer();
	FPlayer(std::string, PlayerType);
	
	// Getters
	int32 GetRoundsWonAmount() const;
	int32 GetPlayerValue() const;
	bool HasEndedRound() const;
	std::string GetPlayerName() const;
	PlayerType GetPlayerType() const;
	// Setters
	void WinRound();
	void AddCard(std::pair<std::string, int32>);
	void EndRound();
	// Workers
	void CompleteReset(std::string, PlayerType);
	void RoundReset();

private:
	std::string Name;
	PlayerType Type;
	TMap<std::string, int32> Cards;
	int32 RoundsWonAmount;
	int32 PlayerValue;
	bool RoundEnded;
};
