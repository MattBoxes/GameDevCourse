#pragma once
#include <string>
using int32 = int;

using FString = std::string;

// All values initialized to zero
struct FBullCowCount {
	int32 Cows = 0;
	int32 Bulls = 0;
};

enum EGuessStatus
{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase

};

class FBullCowGame {
public:
	FBullCowGame(); // contsructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const; //TODO : Make a richer return value
	void Reset();
	
	//Counts Bulls and Cows assuming valid guess
	FBullCowCount SubmitValidGuess(FString);


private: 
	bool bIsGameWon;
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool IsIsogram(FString) const;
};