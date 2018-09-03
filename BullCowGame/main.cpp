/* This is the console executable, that makes use of the BullCow class
this acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = Fstring;
using int32 = int;

void PrintIntro();
void PlayGame();
Ftext GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

//the entry point for our application
int main()
{	
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0; //exit the application
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries
	constexpr int32 NUM_GUESSES = 5;
	for (int32 x = 0; x < NUM_GUESSES; ++x) {
		Ftext Guess = GetGuess(); // TODO make loop checking valid

		// submit valid guess to the game
		// print number of bulls and cows

		std::cout << "your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
	
	// TODO summarize game
	return;
}


//get a guess from the player
Ftext GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	Ftext Guess = "";

	CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry <<". Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?";
	Ftext Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}


//introduce the game
void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game. ";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?";
	std::cout << std::endl;
	return;
}