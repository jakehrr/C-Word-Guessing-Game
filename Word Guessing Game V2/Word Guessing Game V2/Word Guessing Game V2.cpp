// Word Guessing Game V2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
// Calling Header file with game classes
#include "WordGuessGame.h"
using namespace std;

// Initialising Functions
void gameIntroduction();
void playGame();
void playerNaming();
bool playAgain();
string validPlayerGuess();
void GameSummary();

wordGuessingGame WWGame; //Instantiate Game

int main()
{
	playerNaming();
	// Game Loop
	bool bWantToPlayAgain = false;
	do {
		gameIntroduction();
		playGame();
		bWantToPlayAgain = playAgain();
	} while (bWantToPlayAgain);

	return 0;
}

void playerNaming()
{


	cout << endl;
	cout << "HAHA! Stop there puny man you may no pass through here! Not for nothing anyway." << std::endl;
	cout << std::endl;


	cout << "          __,='`````'=/__	" << std::endl;
	cout << "         '//  (o) /(o) / `'         _,-,	" << std::endl;
	cout << "         //|     ,_)   (`/      ,-'`_,-/	" << std::endl;
	cout << "       ,-~~~/  `'==='  /-,      /==```` /__	" << std::endl;
	cout << "      /        `----'     `/     /       //	" << std::endl;
	cout << "   ,-`                  ,   /  ,.-/       /	" << std::endl;
	cout << "  /      ,               /,-`/`_,-`/_,..--'/	" << std::endl;
	cout << " ,`    ,/,              ,>,   )     /--`````/  " << std::endl;
	cout << " (      `/`---'`  `-,-'`_,<   /      /_,.--'`	" << std::endl;
	cout << "  `.      `--. _,-'`_,-`  |    /	" << std::endl;
	cout << "   [`-.___   <`_,-'`------(    /	" << std::endl;
	cout << "   (`` _,-/   / --`````````|--`" << std::endl;
	cout << "	 >-`_,-`/,-` ,          |" << std::endl;
	cout << "	<`_,'     ,  //          /" << std::endl;
	cout << "    `  ///,-/ `/  //`/_/V/_/" << std::endl;
	cout << "	    (  ._. )    ( .__. )" << std::endl;
	cout << "	    |      |    |      |" << std::endl;
	cout << "       /,---_|    |_---./" << std::endl;
	cout << "       ooOO(_)    (_)OOoo" << std::endl;

	// Player Name

	cout << "If you wish to pass you must guess the " << WWGame.GetHiddenWordLength() << " letter isogram i'm thinking of" << std::endl;
	cout << endl;
}

void gameIntroduction()
{
	// Game Introduction 

	cout << "I am thinking of a " << WWGame.GetHiddenWordLength() << " letter isogram word, can you guess the word?" << endl;
	cout << "    (An isogram is a word with no repeating letters)" << endl;
	cout << endl;
}

void playGame()
{
	// Calling reset function - See constructors
	WWGame.reset();
	int MaxTries = WWGame.GetMaxTries();
	
	// Telling player how many attempts they have to guess hidden word. 
	cout << "You will have " << MaxTries << " attempts to guess the word!" << endl;
	cout << endl;
	
	// Game Loop 
	while ( ! WWGame.IsGameWon() && WWGame.GetCurrentTry() <= MaxTries)
	{
		std::string Guess = validPlayerGuess();
		
		// Finding out whether they have input enough letters. 
		RightWrongCount RightWrongCount = WWGame.SubmitGuess(Guess);

		//repeating guess back to the player 
		cout << "Letters you got correct!: " << RightWrongCount.Right;
		cout << ". Letters in the wrong place!: " << RightWrongCount.Wrong << endl;
		cout << endl;

	}
	GameSummary();
	return;
}

bool playAgain()
{
	cout << "Would you like to play the game again, using the same word? (y/n)" << endl;
	std::string Response = "";
	getline(cin, Response);

	// Player Input
	return (Response[0] == 'y' || Response[0] == 'Y');
}

std::string validPlayerGuess()
{
	WordStatus Status = WordStatus::Invalid_Status;
	std::string Guess = "";
	do {
		int MyCurrentTry = WWGame.GetCurrentTry();
		//Getting a guess from the player 
		cout << "Try " << MyCurrentTry << ". What is your guess?:" << endl;
		getline(cin, Guess);

		Status = WWGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case WordStatus::Wrong_Length:
			cout << "Yo dude that isn't a " << WWGame.GetHiddenWordLength() << " letter word. Try again bro" << endl;
			cout << endl;
			break;
		}
	} while (Status != WordStatus::OK); // Loop until valid input
	return Guess;
}

void GameSummary()
{
	if (WWGame.IsGameWon()) 
	{
		cout << "I didn't believe it... YOU WIN!" << endl;
	}
	else 
	{
		cout << "Knew it... You lost. Wanna play again?" << endl;
	}
}