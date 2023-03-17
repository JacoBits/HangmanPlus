#pragma once
#ifndef GAMECOMMANDS_H
#define GAMECOMMANDS_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <ctype.h>

struct difficulty {
	int totalAttempts = 10;
	bool displaySpaces = true;
	bool displayRepeated = true;
	std::vector<std::string> wordBank;
};

class GameCommands
{
public:

	//
	void InitializeDifficultySettings();
	//
	void SelectDifficulty();
	//
	void PickAWord();
	//
	void GetUserInput();
	//
	bool ValidateUserInput();
	//
	bool CheckRepeatedGuess();
	//
	bool ValidateWordInput();
	//
	void IsLetterInWord();
	//
	bool CheckIfWordGuessed();
	//
	bool CheckIfGameOver();
	//
	int GetAttemptsLeft() { return attemptsLeft; }
	//
	std::string GetWordToGuess() { return chosenWord; }
	//
	std::vector<char> GetGuessedLetters() { return guessedLetters; }
	//
	difficulty* GetChosenDifficulty() { return chosenDifficulty; }
	//
	void ResetUsedLetters() { usedLetters.clear(); }

private:
	int attemptsLeft; //

	difficulty regular; //
	difficulty hard; //
	difficulty challenge; //
	difficulty impossible; //

	difficulty* chosenDifficulty; //

	std::string chosenWord; //
	std::vector<char> lettersInWord; //

	char userGuess; //
	std::string guessWord = " "; //

	std::vector<char> usedLetters; //
	std::vector<char> guessedLetters; //
};



#endif