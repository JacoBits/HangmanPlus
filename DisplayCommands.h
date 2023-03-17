#pragma once
#ifndef DISPLAYCOMMANDS_H
#define DISPLAYCOMMANDS_H

#include <iostream>

class DisplayCommands
{
public:

	//
	void DisplayIntro();

	//
	void DisplayDifficultyScreen();

	//
	void DisplayHangman(int guessesLeft);

	//
	void DisplayWordSpaces(std::string chosenWord);

};

#endif