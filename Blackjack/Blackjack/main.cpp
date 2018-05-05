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
void PrintRoundIntro();
void AssignNewCard(FPlayer *ConcernedPlayer);
void PrintPlayerValue(FPlayer);
void DrawInitialCard(FPlayer *ConcernedPlayer, int32 Turn);
void DrawInitialCards();

FBlackjackGame BlackjackGame(3); // Game instance
FPlayer Player("Player", PlayerType::Human);
FPlayer AI("AI", PlayerType::AI);

// Entry point of the console application
int main()
{
	do
	{
		IntroduceGame();
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
	Player.Reset("Player", PlayerType::Human);
	AI.Reset("AI", PlayerType::AI);

	// Loop until a player has won enough rounds
	// TODO: Add step by step progress ?
	do
	{
		PrintRoundIntro();		
		DrawInitialCards();

		// Loop until there's a winner (turns)
			// If Player didn't end his round, Player turn (PLAYER VALUE = X) 
				// Draw a card
					// card3 (value of..)
					// Your PLAYER VALUE is X
					// If PLAYER VALUE > 21 
						// Then Player loses round (exit loop)
					// If PLAYER VALUE = 21 
						// Then Player wins round (exit loop)
					// Else
						// Continue
				// End round
					// You end round with a PLAYER VALUE of X
					// Player turn is ignored until end of round

			// AI turn 
				// Draw a card
					// If AI PLAYER VALUE > 21 
						// Then AI loses round (exit loop)
					// If AI PLAYER VALUE = 21 
						// Then AI wins round (exit loop)
					// Else
						// Continue
				// End round
					// AI ends round with a PLAYER VALUE of X
					// AI turn is ignored until end of round
		// Turns loop end		
	// Rounds loop end
	} while (!GameHasAWinner());

	// Player 3 - 2 AI (example)
	// Congratulate the winner of the game
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
	std::cout << " - Draw a random card (which value will add up to his PLAYER VALUE)\n";
	std::cout << " - End the round (the player will skip all his turns until the other player loses the game or ends his turn)\n";
	std::cout << std::endl;
}

// Ask the player if he is ready to play the game
void AskPlayerReady()
{
	std::cout << "Press Enter to start playing..." << std::endl;
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
	return true;
	//return (Player.GetRoundsWonAmount() >= BlackjackGame.GetAmountOfRoundsToWin() ||
	//	AI.GetRoundsWonAmount() >= BlackjackGame.GetAmountOfRoundsToWin());
}

// Prints the current round and the scores
void PrintRoundIntro()
{
	std::cout << "----------------------------\n";
	std::cout << "- Round " << BlackjackGame.GetCurrentRound() << ", ";
	std::cout << "Player " << Player.GetRoundsWonAmount() << " - " << AI.GetRoundsWonAmount() << " AI -\n";
	std::cout << "----------------------------\n\n";
}

// Draws a new card to a given Player, and display informations about it
void AssignNewCard(FPlayer *ConcernedPlayer)
{
	std::pair<std::string, int32> DrawnCard = BlackjackGame.DrawCard(); // Draw and store new card
	if (DrawnCard.second != 111) // card is NOT an Ace
	{
		ConcernedPlayer->AddCard(DrawnCard); // Add card to player's cards
		std::cout << ConcernedPlayer->GetPlayerName() << " draws a " << DrawnCard.first;
		std::cout << " which has a value of " << DrawnCard.second << std::endl;
	}
	else // card is an Ace
	{
		if (ConcernedPlayer->GetPlayerType() == PlayerType::Human) // if player draws an Ace
		{
			std::cout << ConcernedPlayer->GetPlayerName() << " draws an " << DrawnCard.first << std::endl;
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
		else if (ConcernedPlayer->GetPlayerType() == PlayerType::AI) // if AI draws and Ace
		{
			// TODO: AI decision making when drawing and ACE
			std::cout << ConcernedPlayer->GetPlayerName() << " draws an " << DrawnCard.first << std::endl;
			std::cout << ConcernedPlayer->GetPlayerName() << " decides to give it a value of 11." << std::endl;
			DrawnCard.second = 11;
			ConcernedPlayer->AddCard(DrawnCard);
		}
	}	
}

// Prints a given player's player value
void PrintPlayerValue(FPlayer ConcernedPlayer)
{
	std::cout << ConcernedPlayer.GetPlayerName() << "'s PLAYER VALUE = " << ConcernedPlayer.GetPlayerValue() << std::endl;
}

// Draws an initial card
void DrawInitialCard(FPlayer *ConcernedPlayer, int32 Turn)
{
	std::cout << ConcernedPlayer->GetPlayerName() << " INITIAL TURN (" << Turn << "/2)" << std::endl;
	std::cout << "-------------------------" << std::endl;
	AssignNewCard(ConcernedPlayer);
	PrintPlayerValue(*ConcernedPlayer);
	std::cout << std::endl;
}

// Draws 2 cards for each player at the beginning of a round
void DrawInitialCards()
{
	DrawInitialCard(&Player, 1); // Player draws 1rst random card		
	DrawInitialCard(&AI, 1); // AI draws 1rst random card
	DrawInitialCard(&Player, 2); // Player draws 2nd random card		
	DrawInitialCard(&AI, 2); // Player draws 2nd random card
}