#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame();
	void Reset(); //Make a rich return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool CheckGuessValidity(FString);
	BullCowCount SubmitGuess(FString Guess);

//Please try and ignore. Focus on interface above.
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	FString randWord[7];
};