#pragma once
#include <string>
enum EGuessStatus
{
	Invalid_Status,
	Wrong_Length,
	Not_Isogram,
	Not_Lower_Case,
	Ok
};


using FString = std::string;
using int32 = int;
struct FBullCowCount
{
	int32 No_of_Bulls = 0;
	int32 No_of_Cows = 0;
};

class FBullCowGame
{
public:
	// Creating a constructor for the program
	FBullCowGame();


	int32 GetHiddenWordLength() const;
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;


	EGuessStatus CheckGuessValidity(FString) const;
	FBullCowCount SubmitGuess(FString PlayerGuess);
	void ResetGame(); // Will be implemented later
private:
	int32 MyCurrentTry;
	int32 MyMaxTry;
	FString MyHiddenWord;
};