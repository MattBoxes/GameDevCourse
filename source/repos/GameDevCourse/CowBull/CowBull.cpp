// CowBull.cpp : Defines the entry point for the console application.
#include <iostream>
#include <string>
#include "FBullCowGame.h"


void Introduction();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();
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
	
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	BCGame.Reset();
	
	for (int counter = 1; counter <= MaxTries; counter++) { // provides 5 guesses
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

void Introduction() { //introduction to game
	constexpr int Word_Length = 9;
	std::cout << "Hello Welcome to Cows and Bulls \n";
	std::cout << "Can you guess the " << Word_Length;
	std::cout << " letter isogram that I'm thinking of?" << std::endl;
	return;
}

std::string GetGuess() { //Function for recieving an returning player guess
	
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << " Enter your guess: " << std::endl;
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (y/n)" << std::endl;
	std::string response;
	std::getline(std::cin, response);
	
	return (response[0] == 'y') || (response[0] == 'Y');
}