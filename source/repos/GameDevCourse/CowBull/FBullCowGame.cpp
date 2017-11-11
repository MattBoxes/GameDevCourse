#include "stdafx.h"
#include "FBullCowGame.h"


// Getter functions
int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

FBullCowGame::FBullCowGame() //Cosntructor
{
	Reset();
}

void FBullCowGame::Reset() //Resets game
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	
	MyCurrentTry = 1;
	
	return;
}
bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
