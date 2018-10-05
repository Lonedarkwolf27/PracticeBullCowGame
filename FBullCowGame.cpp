#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	ResetGame();
}



void FBullCowGame::ResetGame()
{
	MyCurrentTry = 1;
	constexpr int MAX_Tries = 10;
	MyMaxTry = MAX_Tries;

	const FString HIDDEN_WORD = "dragon";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTry;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(std::string Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lower_Case;
	}
	else if (Guess.length() != GetHiddenWordLength() )
	{
		return EGuessStatus::Wrong_Length;
	}
	else 
	{
		return EGuessStatus::Ok;
	}
}

FBullCowCount FBullCowGame::SubmitGuess(FString PlayerGuess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 LengthOfMyHiddenWord = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < LengthOfMyHiddenWord; MHWChar++)
	{
		for (int32 GChar = 0; GChar < LengthOfMyHiddenWord; GChar++)
		{
			if (PlayerGuess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar)
				{
					BullCowCount.No_of_Bulls++;
				}
				else
				{
					BullCowCount.No_of_Cows++;
				}
			}
		}
	
	}
	return BullCowCount;
}