// Word Guessing Game V2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "WordGuessGame.h"

void gameIntroduction();
void playGame();
bool playAgain();
std::string playerGuess();

wordGuessingGame WWGame; //Instantiate Game

int main()
{
	bool bWantToPlayAgain = false;
	do {
		gameIntroduction();
		playGame();
		bWantToPlayAgain = playAgain();
	} while (bWantToPlayAgain);

	return 0;
}


void gameIntroduction()
{
	// Game Introduction 
	constexpr int LENGTH_OF_WORD = 9;

	std::cout << "          Welcome to this word guessing game!" << std::endl;
	std::cout << "I am thinking of a " << LENGTH_OF_WORD << " isogram word, can you guess the word?" << std::endl;
	std::cout << "    (An isogram is a word with no repeating letters)" << std::endl;
	std::cout << std::endl;
}

void playGame()
{
	WWGame.reset();

	int MaxTries = WWGame.GetMaxTries();
	std::cout << "You will have " << MaxTries << " attempts to guess the word!" << std::endl;
	std::cout << std::endl;
	// Game Loop 
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = playerGuess();
		//repeating guess back to the player 
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

bool playAgain()
{
	std::cout << "Would you like to play the game again? (y/n)" << std::endl;
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

std::string playerGuess()
{
	int MyCurrentTry = WWGame.GetCurrentTry();
	//Getting a guess from the player 
	std::cout << "Try " << MyCurrentTry << ". What is your guess?:" << std::endl;
	std::string Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}