#include "FBullCowGame.h"

using int32 = int;


FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const{ return MyCurrentTry; }


//Resets the game and changes the word accordingly
void FBullCowGame::Reset()
{
	FString randWord[7] = { "angel", "candy", "melon", "roman" , "lemon", "fairy", "pixie" };
	const FString MY_HIDDEN_WORD = randWord[rand() % 8];
	MyHiddenWord = MY_HIDDEN_WORD;
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	return;
}


//This would be for validation, but I never got the chance to add it.
bool FBullCowGame::CheckGuessValidity(FString f)
{
	return false;
}

//This goes through the world looking for letter matches
BullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	BullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	
	for (int32 i = 0; i < HiddenWordLength;i++) {
		for (int32 j = 0; j < HiddenWordLength;j++) {
			if (Guess[i] == MyHiddenWord[j])
			{
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}
