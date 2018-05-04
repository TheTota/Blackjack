/*
	AUTHOR: Thomas CIANFARANI
	CONTEXT: Game to consolidate my new C++ skills.
	DESCRIPTION:
	This is the console executable that makes use of the Blackjack class.
	This acts as the view in a MVC pattern and is responsible for all user
	interaction. For game logic see the FBlackjack class.
*/

#pragma once
#include <iostream>
#include <string>
#define int32 int

// Prototypes
void IntroduceGame();
void PrintGameIntro();
void HandleInstructionsPrinting();
void PrintInstructions();
void AskPlayerReady();
bool AskToPlayAgain();
void PlayGame();

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

void IntroduceGame()
{
	PrintGameIntro();
	HandleInstructionsPrinting();
	AskPlayerReady();
}

// Plays a single game to completion
void PlayGame()
{
	// Loop until a player has won enough rounds
		// Round 1, Player 0 - 0 AI (example)
	
		// You draw 2 random cards:
			// card1 (value of..)
			// card2 (value of..)
			// Your PLAYER VALUE is X
	
		// AI draws 2 random cards
			// card1 (value of..)
			// card2 (value of..)
			// AI PLAYER VALUE is Y

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
	std::cout << "Blackjack is 2 players game using classic playing cards, that requires strategy and luck." << std::endl;
	std::cout << "Here you will face an artificial intelligence." << std::endl;
	std::cout << std::endl;
	std::cout << "One game consists of multiple rounds." << std::endl;
	std::cout << "One round consists in consecutive turns taken by each player (player1, player2, player1, etc)." << std::endl;
	std::cout << "First player to win X rounds wins the game." << std::endl; // TODO: Add amount of round to win from Blackjack class
	std::cout << std::endl;
	std::cout << "During a round, players will draw cards whose values will add up to make a PLAYER VALUE." << std::endl;
	std::cout << "The goal of a player is to get his PLAYER VALUE as close as possible to the value of 21." << std::endl;
	std::cout << "If a player has his PLAYER VALUE reach a value above 21, he will lose the round." << std::endl;
	std::cout << "If a player reaches the exact value of 21, he will instantly win the round." << std::endl;
	std::cout << std::endl;
	std::cout << "Number cards have their normal value (e.g. 3 heart = 3)." << std::endl;
	std::cout << "Special cards such as jack, queen and king have a value of 10." << std::endl;
	std::cout << "Aces have a value of 1 or 10 which is up to the player." << std::endl;
	std::cout << "Again, the value of each card that a player possesses will add up to make his PLAYER VALUE." << std::endl;
	std::cout << std::endl;
	std::cout << "At the beginning of each round, both players draw 2 random cards." << std::endl;
	std::cout << "During his turn, a player has 2 options :" << std::endl;
	std::cout << " - Draw a random card (which value will add up to his PLAYER VALUE)" << std::endl;
	std::cout << " - End the round (the player will skip all his turns until the other player loses the game or ends his turn)" << std::endl;
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
