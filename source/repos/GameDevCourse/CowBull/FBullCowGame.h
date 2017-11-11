#pragma once
#include <string>


class FBullCowGame {
public:
	FBullCowGame(); // contsructor
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset();
	bool CheckGuessValidity(std::string); //TODO : Make more substance


private: 
	int MyCurrentTry;
	int MyMaxTries;
};