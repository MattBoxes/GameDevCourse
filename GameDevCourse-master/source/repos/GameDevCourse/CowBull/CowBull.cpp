/*Console executable. Makes use of bullcow class, responsible for user interaction*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int; 

void Introduction();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();
FBullCowGame BCGame; // Instantiate a new game

int main()
{
	bool PlayAgain = false;
	do {
		Introduction();
		PlayGame();
		PlayAgain = AskToPlayAgain();
		
	} while (PlayAgain);


	return 0; // Ends the Game
	
}

void PlayGame()
{
	
	int32 MaxTries = BCGame.GetMaxTries();
	BCGame.Reset();
	
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) { // provides 8 guesses
		FText Guess = GetValidGuess();
		//Recieves guess count
		
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();
	return;
}

void Introduction() { //introduction to game
	
	std::cout << "Hello Welcome to Cows and Bulls \n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram that I'm thinking of?" << std::endl;
	return;
}

FText GetValidGuess() // TODO make GetValidGuess
{ 
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid;
	do {
		//Function for recieving an returning player guess

		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " Enter your guess: " << std::endl;
		std::getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters. \n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters. \n";
			break;
		default:
			// assuming the guess is valid
			break;
		} 
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // Keep looping until we get no errors
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again with the same hidden word? (y/n)" << std::endl;
	FText response;
	std::getline(std::cin, response);
	
	return (response[0] == 'y') || (response[0] == 'Y');
}

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "Congradulations you have won the game! \n";
	}
	else {
		std::cout << "Game Over!\n";
	}
	return;
}