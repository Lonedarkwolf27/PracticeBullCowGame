/// This is where i store my preprocessing directives
/// Preprocessing Directives are the files that contain operational code
/// When we build this solution, the compiler straight goes to the files
/// and copy pastes these codes


/* Now we create BullCow class which will be the main component of this game.
This class will initiate the game, reset it and do all the main required operations with it.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// Adding FText to our string
// Adding int32 to out code
using FText = std::string;
using int32 = int;

// Initializing functions used in main
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

//Creating an instance of a new game
FBullCowGame BCGame;




// Main is the entry point of the our code
int main(void)
{
	//Having a variable to make AskToPlayAgain return output to
	bool bPlayAgain = false;

	// Creating a do while loop that makes AskToPlayAgain function work
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	return 0;
}

// Creating a function for intro
void PrintIntro()
{
	// Constant Expression means a constant value that can be compiled or evaluated just now
	
	// Std is the namespace for identifiers. Basically if two codes have same function name
	// then namespace will seperate from what library we are calling
	// cout uses an overloaded operator
	// Now we need to get return 0 status on the next line so we put an std on endl or end line

	std:: cout << "Welcome to Bulls and Cow Game" << std::endl;
	std:: cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std:: cout << "  letter isogram word I am thinking of ?" << std:: endl;





	return;
}

// Creating a function which holds game's data
void PlayGame()
{

	int32 MaxTries = BCGame.GetMaxTries();

	// Entering for loop to repeat the guesses
	// We have number of turns
	constexpr int32 NoOfTurns = 10;
	for (int32 repeatition = 1; repeatition <= NoOfTurns; repeatition++)
	{
		FText PlayerGuess = GetValidGuess();
		
		FBullCowCount BullCowCount = BCGame.SubmitGuess(PlayerGuess);
		std:: cout << "Your last entered guess was " << PlayerGuess << std:: endl;
		std::cout << "Bulls : " << BullCowCount.No_of_Bulls;
		std::cout << " Cows : " << BullCowCount.No_of_Cows << std::endl;

	}
}


// Creating a function that takes Guess
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";

		// Taking a variable from the user for taking input
		FText PlayerGuess = "";

		// Taking input from the user to absorb what is being said
		// We are using getline because getline allows us to read through any spaces by default
		// and basically takes sentire string till it reaches new line
		std::cout << "Please enter your guess: ";
		std::getline(std::cin, PlayerGuess);

		EGuessStatus Status = BCGame.CheckGuessValidity(PlayerGuess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lower_Case:
			std::cout << "Please only enter " << BCGame.GetHiddenWordLength() << " leters in small caps.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please only enter a " << BCGame.GetHiddenWordLength() << " letters isogram";
			break;
		default:
			return PlayerGuess;
		}

		// Return 0 means status 0 which is press any key to continue  
	} 
	while (Status == EGuessStatus::Ok);
}

bool AskToPlayAgain()
{
	std:: cout << "Do you want to play again ?" << std:: endl;
	std:: cout << "If yes then type yes otherwise type no" << std:: endl;
	FText Response = "";
	std::getline(std:: cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}
