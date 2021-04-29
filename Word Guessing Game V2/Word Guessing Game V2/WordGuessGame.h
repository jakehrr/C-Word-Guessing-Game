#pragma once
#include <string>.


struct RightWrongCount 
{
	int Right = 0;
	int Wrong = 0;
};

enum class WordStatus 
{
	Invalid_Status,
	OK,
	Wrong_Length,
};

class wordGuessingGame
{
public:
	wordGuessingGame(); //Consturctor
	
						// Variables which values will not change throughout the game
	int GetMaxTries() const;
	int GetCurrentTry() const;
	int GetHiddenWordLength() const;
	
	bool IsGameWon() const;
	WordStatus CheckGuessValidity(std::string) const;
	
	void reset();
	RightWrongCount SubmitGuess(std::string);

private:
	int MyCurrentTry;
	int MyMaxTries;
	std::string MyHiddenWord;
	bool gameWon;
};
