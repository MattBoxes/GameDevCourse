#include "stdafx.h"
#include "FBullCowGame.h"
#include <map>
#define TMap std::map


using int32 = int;


// Getter functions
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const {return bIsGameWon; }


FBullCowGame::FBullCowGame() { Reset();} // constructor
void FBullCowGame::Reset() //Resets game
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bIsGameWon = false;
	
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) //if guess isnt isogram 
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) //if guess isnt lowercase 
	{
		return EGuessStatus::Not_Lowercase;
	}	
	else if (GetHiddenWordLength() != Guess.length()) //if guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else //otherwise return OK
	{
		return EGuessStatus::OK;
	}
}

// Recieves a valids guess, increments turns, and returns count.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess
	//loop through all letters in hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		//loop though guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) { 
			if(Guess[GChar] == MyHiddenWord[MHWChar]){ // compares words
				if(MHWChar == GChar){
				BullCowCount.Bulls++;
				}
				else {
				BullCowCount.Cows++;
				}
			}
		}	
	}		
	if (BullCowCount.Bulls == WordLength) {
		bIsGameWon = true;
	}
	else
	{
		bIsGameWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	//loop through all letters
			//if letter is in the map reutrn false
			//otherwise add letter to map
	return true;
}
