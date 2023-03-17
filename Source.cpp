#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<ctype.h>
#include<vector>

#include "GameCommands.h"
#include "DisplayCommands.h"
using namespace std;


void DisplayGuessedLetters(string wordGuess, vector<char> guessedLetters); //DisplayCommands


int main() {
	DisplayCommands hangmanGame;
	GameCommands hangManPlus;

	hangManPlus.InitializeDifficultySettings();
	
	hangmanGame.DisplayIntro();
	bool quit = false;
	char op;

	do {
		hangmanGame.DisplayDifficultyScreen();

		hangManPlus.SelectDifficulty();
		cout << endl << endl;

		difficulty* chosenDifficulty = hangManPlus.GetChosenDifficulty();

		hangManPlus.PickAWord();

		string chosenWord = hangManPlus.GetWordToGuess();

		if (chosenDifficulty->displaySpaces)
			hangmanGame.DisplayWordSpaces(chosenWord);
		else
			cout << "The word is " << chosenWord.length() << " letters long" << endl;

		bool attemptsRemaining = true;
		bool wordGuessed = false;

		vector<char> guessedLetters;

		int guessesLeft;

		do {
			wordGuessed = false;
			attemptsRemaining = true;

			string totalGuess = " ";

			hangManPlus.GetUserInput();

			hangManPlus.IsLetterInWord();

			wordGuessed = hangManPlus.CheckIfWordGuessed();

			cout << endl;

			guessedLetters = hangManPlus.GetGuessedLetters();
			guessesLeft = hangManPlus.GetAttemptsLeft();

			if (chosenDifficulty->displaySpaces)
				DisplayGuessedLetters(totalGuess, guessedLetters);

			hangmanGame.DisplayHangman(guessesLeft);

			if (wordGuessed)
				cout << endl << "Congratulations! You Win!" << endl;

			//cout << "Number of guesses left: " << guessesLeft << endl;
			cout << endl;

			attemptsRemaining = !hangManPlus.CheckIfGameOver();


		} while ((attemptsRemaining && !wordGuessed) || (!attemptsRemaining && wordGuessed));

		cout << "Do you want to play again? [Y/N]" << endl;
		cin >> op;

		if (toupper(op) == 'N')
			quit = true;
		else
			hangManPlus.ResetUsedLetters();

	} while (!quit);

	cin.ignore();

	return 0;
}

//Displays the letters the user has guessed in the word
void DisplayGuessedLetters(string wordGuess, vector<char> guessedLetters)
{
	if (wordGuess == " ")
	{
		for (char letter : guessedLetters)
		{
			cout << letter;
			cout << " ";
		}
		cout << endl; 
		for (char letter : guessedLetters)
		{
			cout << "-";
			cout << " ";
		}
		cout << endl;
		cout << endl << endl;
	}
}
