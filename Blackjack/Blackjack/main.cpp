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
	std::cout << "Game is playing" << std::endl;
	// TODO: Play Game method
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
	std::cout << "Would you like to read the rules of blackjack (y/n)? ";
	std::string Input = "";
	std::cin >> Input;
	if (Input[0] == 'y')
	{
		std::cout << "Some instructions..." << std::endl;
		// TODO: Write instructions
	}
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
