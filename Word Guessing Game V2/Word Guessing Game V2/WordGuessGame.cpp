#include "WordGuessGame.h"
#include <string>

wordGuessingGame::wordGuessingGame() 
{ 
	reset(); 
}

int wordGuessingGame::GetMaxTries() const 
{ 
	return MyMaxTries; 
}

int wordGuessingGame::GetCurrentTry() const 
{ 
	return MyCurrentTry; 
}

int wordGuessingGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

void wordGuessingGame::reset()
{
	constexpr int MaxTries = 7;
	MyMaxTries = MaxTries;

	const std::string HIDDEN_WORD = "planet"; 
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	gameWon = false;
	return;
}

RightWrongCount wordGuessingGame::SubmitGuess(std::string Guess)
{
	MyCurrentTry++;

	RightWrongCount RightWrongCount;
	int HiddenWordLength = MyHiddenWord.length();
	// Counting how many letters the player has got right or wrong.
	for (int HWChar = 0; HWChar < HiddenWordLength; HWChar++) 
	{
		for (int GChar = 0; GChar < HiddenWordLength; GChar++) 
		{
			if (Guess[GChar] == MyHiddenWord[HWChar]) 
			{
				if (HWChar == GChar) 
				{
					RightWrongCount.Right++;
				}
				else 
				{
					RightWrongCount.Wrong++;
				}
			}
		}
	}
	if (RightWrongCount.Right == HiddenWordLength) 
	{
		gameWon = true;
	}
	else 
	{
		gameWon = false;
	}
	return RightWrongCount;
}

bool wordGuessingGame::IsGameWon() const
{
	return gameWon;
}

WordStatus wordGuessingGame::CheckGuessValidity(std::string Guess) const
{
	
	if (Guess.length() != GetHiddenWordLength())
	{
		return WordStatus::Wrong_Length;
	}
	else
	{
		return WordStatus::OK;
	}
}
