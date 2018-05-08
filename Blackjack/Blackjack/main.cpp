/*
	AUTHOR: Thomas CIANFARANI
	CONTEXT: Blackjack game to consolidate my new C++ skills.
	DESCRIPTION:
	This is the console executable that makes use of the Blackjack class.
	This acts as the view in a MVC pattern and is responsible for all user
	interaction. For game logic see the FBlackjack class.
*/

#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "FBlackjackGame.h"
#include "FPlayer.h"
using int32 = int;

// Prototypes
void IntroduceGame();
void PrintGameIntro();
void HandleInstructionsPrinting();
void PrintInstructions();
void AskPlayerReady();
bool AskToPlayAgain();
void PlayGame();
bool GameHasAWinner();
FPlayer GetGameWinner();
bool RoundHasAWinner();
FPlayer* GetRoundWinner();
void PrintRoundIntro();
void AssignNewCard(FPlayer *ConcernedPlayer);
void PrintPlayerValue(FPlayer);
void DrawInitialCard(FPlayer *ConcernedPlayer, int32 Turn);
void DrawInitialCards();
void PrintTurnIntro(FPlayer ConcernedPlayer);
PlayerAction GetPlayerAction(FPlayer ConcernedPlayer);
void RoundResetPlayers();
void AddStep();

FBlackjackGame BlackjackGame(3); // Game instance
FPlayer Player("Player", PlayerType::Human);
FPlayer AI("AI", PlayerType::AI);

FPlayer FirstPlayerToEndRound;

// Entry point of the console application
int main()
{
	IntroduceGame();
	do
	{
		PlayGame();
	} while (AskToPlayAgain());

	return 0; // exit application
}

// Introduces the game with a simple intro and instructions
void IntroduceGame()
{
	PrintGameIntro();
	HandleInstructionsPrinting();
	AskPlayerReady();
}

// Plays a single game to completion
void PlayGame()
{
	BlackjackGame.Reset(3);
	Player.CompleteReset("Player", PlayerType::Human);
	AI.CompleteReset("AI", PlayerType::AI);

	// Loop until a player has won enough rounds
	do
	{
		system("cls"); // Clears console at the beginning of the round
		// TODO: Fix spacing bug after being asked something (ace, action..) and pressing enter with empty input
		// TODO: Fix AI having the first turn after initial turns (happened round 3,4)
		// TODO: See issue on GH
		PrintRoundIntro();
		DrawInitialCards();

		// Loop until there's a round winner (turns)
		while (!RoundHasAWinner())
		{
			if (BlackjackGame.GetCurrentTurn() == Turn::PlayerTurn) // Player's turn
			{
				PrintTurnIntro(Player);
				AddStep();

				// if Player decided to stand in a previous turn
				if (Player.HasEndedRound())
				{
					std::cout << Player.GetName() << " has ended his round.\n";
				}
				else
				{
					if (GetPlayerAction(Player) == PlayerAction::Hit) // if Player decides to Hit
					{
						AssignNewCard(&Player); // Draw a new card
						AddStep();
					}
					else // if Player decides to Stand
					{
						Player.EndRound();
						FirstPlayerToEndRound = Player;
						std::cout << Player.GetName() << " decides to end his round.\n";
						AddStep();
					}
				}

				PrintPlayerValue(Player);
				BlackjackGame.NextTurn();
				AddStep();
			}
			else if (BlackjackGame.GetCurrentTurn() == Turn::AITurn) // AI's turn
			{
				// AI Turn
				PrintTurnIntro(AI);
				AddStep();

				// if AI decided to stand in a previous turn
				if (AI.HasEndedRound())
				{
					std::cout << AI.GetName() << " has ended his round.\n";
				}
				else
				{
					if (GetPlayerAction(AI) == PlayerAction::Hit) // if AI decides to Hit
					{
						AssignNewCard(&AI); // Draw a new card
					}
					else // if AI decides to Stand
					{
						AI.EndRound();
						FirstPlayerToEndRound = AI;
						std::cout << AI.GetName() << " decides to end his round.\n";
					}
				}

				PrintPlayerValue(AI);
				BlackjackGame.NextTurn();
				AddStep();
			}
		} // Turns loop end	

		// Print round winner
		FPlayer *RoundWinner = GetRoundWinner();
		std::cout << RoundWinner->GetName() << " wins the round!\n";
		RoundWinner->WinRound();

		// Round end actions
		BlackjackGame.NextRound();
		RoundResetPlayers();
		AddStep();
	} while (!GameHasAWinner()); // Rounds loop end

	// Print score
	std::cout << "Score of the game : " << Player.GetName() << " " << Player.GetRoundsWonAmount();
	std::cout << " - " << AI.GetRoundsWonAmount() << " " << AI.GetName();
	std::cout << std::endl;

	// Congratulate the winner of the game
	std::cout << "Congratulations to the winner, " << GetGameWinner().GetName() << "!\n";
	AddStep();
}

// Prints the simple introduction to the game
void PrintGameIntro()
{
	std::cout << "Welcome to the game of Blackjack!" << std::endl;
	// TODO: Add ASCII art here 
}

// Displays game instructions if players wants to see them
void HandleInstructionsPrinting()
{
	std::cout << "Would you like to read the rules of Blackjack (y/n)? ";
	std::string Input = "";
	std::cin >> Input;
	if (Input[0] == 'y')
	{
		PrintInstructions();
	}
}

void PrintInstructions()
{
	std::cout << std::endl;
	std::cout << "Blackjack is 2 players game using classic playing cards, that requires strategy and luck.\n";
	std::cout << "Here you will face an artificial intelligence.\n";
	std::cout << std::endl;
	std::cout << "One game consists of multiple rounds.\n";
	std::cout << "One round consists in consecutive turns taken by each player (player1, player2, player1, etc).\n";
	std::cout << "First player to win " << BlackjackGame.GetAmountOfRoundsToWin() << " rounds wins the game.\n";
	std::cout << std::endl;
	std::cout << "During a round, players will draw cards whose values will add up to make a PLAYER VALUE.\n";
	std::cout << "The goal of a player is to get his PLAYER VALUE as close as possible to the value of 21.\n";
	std::cout << "If a player has his PLAYER VALUE reach a value above 21, he will lose the round.\n";
	std::cout << "If a player reaches the exact value of 21, he will instantly win the round.\n";
	std::cout << std::endl;
	std::cout << "Number cards have their normal value (e.g. 3 heart = 3).\n";
	std::cout << "Special cards such as jack, queen and king have a value of 10.\n";
	std::cout << "Aces have a value of 1 or 11 which is up to the player.\n";
	std::cout << "Again, the value of each card that a player possesses will add up to make his PLAYER VALUE.\n";
	std::cout << std::endl;
	std::cout << "At the beginning of each round, both players draw 2 random cards.\n";
	std::cout << "During his turn, a player has 2 options :\n";
	std::cout << " - Hit : Draw a random card (which value will add up to his PLAYER VALUE)\n";
	std::cout << " - Stand : End the round (the player will skip all his turns until the other player loses the game or ends his turn)\n";
	std::cout << std::endl;
}

// Ask the player if he is ready to play the game
void AskPlayerReady()
{
	std::cout << "Press Enter to progress in the game..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}

// Asks the player if he wants to play again
bool AskToPlayAgain()
{
	std::cout << "Would you like to play again (y/n)? ";
	std::string Input = "";
	std::cin >> Input;
	if (Input[0] == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Returns whether the game has a winner or not
bool GameHasAWinner()
{
	return (Player.GetRoundsWonAmount() >= BlackjackGame.GetAmountOfRoundsToWin() ||
		AI.GetRoundsWonAmount() >= BlackjackGame.GetAmountOfRoundsToWin());
}

// Returns the winner of the game
FPlayer GetGameWinner()
{
	if (Player.GetRoundsWonAmount() >= BlackjackGame.GetAmountOfRoundsToWin())
	{
		return Player;
	}
	else if (AI.GetRoundsWonAmount() >= BlackjackGame.GetAmountOfRoundsToWin())
	{
		return AI;
	}

	// in case
	return Player;
}

// Returns whether the round has a winner or not
bool RoundHasAWinner()
{
	bool ValueCase = (Player.GetPlayerValue() >= 21 || AI.GetPlayerValue() >= 21);
	bool StandCase = (Player.HasEndedRound() && AI.HasEndedRound());

	return (ValueCase || StandCase);
}

// Returns the round winner if there is any
FPlayer* GetRoundWinner()
{
	// Check if a player has reached the value of 21 
	if (Player.GetPlayerValue() == 21)
	{
		return &Player;
	}
	else if (AI.GetPlayerValue() == 21)
	{
		return &AI;
	}

	// Check if a player has reached a value above 21
	if (Player.GetPlayerValue() > 21)
	{
		return &AI;
	}
	else if (AI.GetPlayerValue() > 21)
	{
		return &Player;
	}

	// Check if both player stand
	if (Player.HasEndedRound() && AI.HasEndedRound())
	{
		if (Player.GetPlayerValue() > AI.GetPlayerValue())
		{
			return &Player;
		}
		else if (Player.GetPlayerValue() < AI.GetPlayerValue())
		{
			return &AI;
		}
		else if (Player.GetPlayerValue() == AI.GetPlayerValue())
		{
			return &FirstPlayerToEndRound;
		}
	}

	// In case..
	return &Player;
}

// Prints the current round and the scores
void PrintRoundIntro()
{
	std::cout << "----------------------------\n";
	std::cout << "- Round " << BlackjackGame.GetCurrentRound() << ", ";
	std::cout << "Player " << Player.GetRoundsWonAmount() << " - " << AI.GetRoundsWonAmount() << " AI -\n";
	std::cout << "----------------------------\n";
	AddStep();
}

// Draws a new card to a given Player, and display informations about it
void AssignNewCard(FPlayer *ConcernedPlayer)
{
	std::pair<std::string, int32> DrawnCard = BlackjackGame.DrawCard(); // Draw and store new card
	if (DrawnCard.second != 111) // card is NOT an Ace
	{
		ConcernedPlayer->AddCard(DrawnCard); // Add card to player's cards
		std::cout << ConcernedPlayer->GetName() << " draws a " << DrawnCard.first;
		std::cout << " which has a value of " << DrawnCard.second << std::endl;
	}
	else // card is an Ace
	{
		if (ConcernedPlayer->GetType() == PlayerType::Human) // if player draws an Ace
		{
			std::cout << ConcernedPlayer->GetName() << " draws an " << DrawnCard.first << std::endl;
			int32 AceValue;
			do
			{
				std::cout << "What value do you want it to take (1 or 11)? ";
				std::cin >> AceValue;
				if (AceValue == 11 || AceValue == 1)
				{
					DrawnCard.second = AceValue;
				}
			} while (AceValue != 11 && AceValue != 1);
			ConcernedPlayer->AddCard(DrawnCard);// Add card to player's cards
		}
		else if (ConcernedPlayer->GetType() == PlayerType::AI) // if AI draws and Ace
		{
			// TODO: AI decision making when drawing and ACE
			std::cout << ConcernedPlayer->GetName() << " draws an " << DrawnCard.first << std::endl;
			std::cout << ConcernedPlayer->GetName() << " decides to give it a value of 11." << std::endl;
			DrawnCard.second = 11;
			ConcernedPlayer->AddCard(DrawnCard);
		}
	}
}

// Prints a given player's player value
void PrintPlayerValue(FPlayer ConcernedPlayer)
{
	std::cout << ConcernedPlayer.GetName() << "'s PLAYER VALUE = " << ConcernedPlayer.GetPlayerValue() << "\n";
}

// Draws an initial card
void DrawInitialCard(FPlayer *ConcernedPlayer, int32 Turn)
{
	std::cout << ConcernedPlayer->GetName() << " INITIAL TURN (" << Turn << "/2)" << std::endl;
	std::cout << "-------------------------";
	AddStep();
	AssignNewCard(ConcernedPlayer);
	PrintPlayerValue(*ConcernedPlayer);
	AddStep();
}

// Draws 2 cards for each player at the beginning of a round
void DrawInitialCards()
{
	DrawInitialCard(&Player, 1); // Player draws 1rst random card		
	DrawInitialCard(&AI, 1); // AI draws 1rst random card
	DrawInitialCard(&Player, 2); // Player draws 2nd random card		
	DrawInitialCard(&AI, 2); // Player draws 2nd random card
}

// Prints turn intro
void PrintTurnIntro(FPlayer ConcernedPlayer)
{
	std::cout << ConcernedPlayer.GetName() << " TURN (PLAYER VALUE = " << ConcernedPlayer.GetPlayerValue() << ")\n";
	std::cout << "-------------------------------";
}

// Returns a PlayerAction for a given player
PlayerAction GetPlayerAction(FPlayer ConcernedPlayer)
{
	if (ConcernedPlayer.GetType() == PlayerType::Human) // Human decision making
	{
		// Ask the player what he wants to do
		std::string Action;
		do
		{
			std::cout << "Chose and action (hit/stand): ";
			std::cin >> Action;
			std::transform(Action.begin(), Action.end(), Action.begin(), ::tolower);
		} while (Action != "hit" && Action != "stand");

		// Hit or stand
		if (Action == "hit")
		{
			return PlayerAction::Hit;
		}
		else if (Action == "stand")
		{
			return PlayerAction::Stand;
		}
	}
	else if (ConcernedPlayer.GetType() == PlayerType::AI) // AI decision making
	{
		// TODO: Handle case:
		// AI has a value above Player's (nobody is standing)
		// Player draws a card and get same value as AI (e.g. 20)
		// Since AI was first to have that value, he can stand and win round
		// TODO: Also explain that case in the instructions
		if (AI.GetPlayerValue() > 16 && Player.GetPlayerValue() < AI.GetPlayerValue())
		{
			return PlayerAction::Stand;
		}
		else
		{
			return PlayerAction::Hit;
		}
	}

	return PlayerAction::Stand;
}

// Resets round values for both players
void RoundResetPlayers()
{
	Player.RoundReset();
	AI.RoundReset();
}

// Adds a step during the execution of the code
// Waits for user input to continue it
void AddStep()
{
	getchar();
}
