#include <iostream>
#include <string>
#include "FBullCowGame.h"
/** This is the exicutible for the bull cow game. 

**/
using FText = std::string; 
using int32 = int;

void PlayGame();
void PrintIntroduction();
FText RecieveGuess(FText Guess);
bool PlayAgain();
FBullCowGame BCGame;
//Main Method
int main() {
	do {
		//Game Procedures 
		PrintIntroduction();
		PlayGame();
	} while (PlayAgain());
	//Return 
	return 0;
}

//Runs the game through a loop
void PlayGame(){
	//Decides the games word and other aspects
	BCGame.Reset();
	int32 CurrentTry = BCGame.GetCurrentTry();
	FText Guess = "";
	int32 MaxGuess = 5;
	//Goes through the game
	for (int32 i = 0;i < MaxGuess; i++) {
		std::cout <<  "\nEnter your guess please: ";
		Guess = RecieveGuess(Guess);
		BullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << "\nCows: " << BullCowCount.Cows << std::endl;
		//Ends if correct
		if (BullCowCount.Bulls == 5) {
			i = MaxGuess;
			std::cout << "You figured it out!";
		}
	}

}

void PrintIntroduction() {
	constexpr int32 WORD_LENGTH = 5;
	//Introduction
	std::cout << "Welcome to Bulls and Cows! The best word game!\n" << "Can you guess the " << WORD_LENGTH << " letter isogram I am thinking of.\n";
	return;
}

FText RecieveGuess(FText Guess) {
	//Guess from player
	std::getline(std::cin, Guess);
	return Guess;
}

bool PlayAgain() {
	//Replay or not
	FText Response = " ";
	std::cout << "Do you wanna play again? (y/n) ";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}