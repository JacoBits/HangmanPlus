#include "DisplayCommands.h"

//Displays the intro message of the game
void DisplayCommands::DisplayIntro() {
	std::cout << "   __ __                                       __ " << std::endl;
	std::cout << "  / // /___ _ ___  ___ _ __ _  ___ _ ___    __/ /_" << std::endl;
	std::cout << " / _  // _ `// _ \\/ _ `//  ' \\/ _ `// _ \\  /_  __/" << std::endl;
	std::cout << "/_//_/ \\_,_//_//_/\\_, //_/_/_/\\_,_//_//_/   /_/   " << std::endl;
	std::cout << "                 /___/                            " << std::endl;
	std::cout << std::endl << std::endl << std::endl;

	std::cout << "Welcome to Hangman+" << std::endl << std::endl;
}

//
void DisplayCommands::DisplayDifficultyScreen() {
	std::cout << "Choose your difficulty: " << std::endl;
	std::cout << "==========================================================" << std::endl;
	std::cout << "| Regular(R) |  Hard(H)   | Challenge(C) | Impossible(I) |" << std::endl;
	std::cout << "==========================================================" << std::endl;
	std::cout << "| 10 guesses | 9 guesses  | 7 guesses    | 6 guesses     |" << std::endl;
	std::cout << "==========================================================" << std::endl;
	std::cout << std::endl;
	std::cout << "All difficulties differ in the number of wrong guesses the user has and the list of words that can be played." << std::endl;
	std::cout << "    -Regular and Harder modes are like regular hangman." << std::endl;
	std::cout << "    -Challenge mode does not display the positions the letters are in" << std::endl;
	std::cout << "    -Impossible mode does not alert the user if a letter they have guessed is found more than once in the word" << std::endl;
	std::cout << "    -Challenge and impossible mode can only be won by typing in the entire word using the ! character" << std::endl;
	std::cout << std::endl;
}


//Displays the hangman depending on how many guesses the user has left to guess the word
void DisplayCommands::DisplayHangman(int guessesLeft) {

	//if guessesLeft reaches negative (it shouldn't) the program treats it as 0, causing a game over
	if (guessesLeft < 0)
		guessesLeft = 0;

	switch (guessesLeft) {
	case 0:
		std::cout << "      ______   " << std::endl;
		std::cout << "      |    |   " << std::endl;
		std::cout << "      |    O   " << std::endl;
		std::cout << "      |   /|\\ " << std::endl;
		std::cout << "      |   / \\ " << std::endl;
		std::cout << "  ____|____    " << std::endl;
		break;
	case 1:
		std::cout << "      ______   " << std::endl;
		std::cout << "      |    |   " << std::endl;
		std::cout << "      |    O   " << std::endl;
		std::cout << "      |   /|\\ " << std::endl;
		std::cout << "      |   /    " << std::endl;
		std::cout << "  ____|____    " << std::endl;
		break;
	case 2:
		std::cout << "      ______   " << std::endl;
		std::cout << "      |    |   " << std::endl;
		std::cout << "      |    O   " << std::endl;
		std::cout << "      |   /|\\ " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "  ____|____    " << std::endl;
		break;
	case 3:
		std::cout << "      ______   " << std::endl;
		std::cout << "      |    |   " << std::endl;
		std::cout << "      |    O   " << std::endl;
		std::cout << "      |   /|   " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "  ____|____    " << std::endl;
		break;
	case 4:
		std::cout << "      ______   " << std::endl;
		std::cout << "      |    |   " << std::endl;
		std::cout << "      |    O   " << std::endl;
		std::cout << "      |    |   " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "  ____|____    " << std::endl;
		break;
	case 5:
		std::cout << "      ______   " << std::endl;
		std::cout << "      |    |   " << std::endl;
		std::cout << "      |    O   " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "  ____|____    " << std::endl;
		break;
	case 6:
		std::cout << "      ______   " << std::endl;
		std::cout << "      |    |   " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "  ____|____    " << std::endl;
		break;
	case 7:
		std::cout << "      ______   " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "  ____|____    " << std::endl;
		break;
	case 8:
		std::cout << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "      |        " << std::endl;
		std::cout << "  ____|____    " << std::endl;
		break;
	case 9:
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "  _________ " << std::endl;
		break;
	case 10:
		std::cout << std::endl;
		std::cout << std::endl;
		break;

	}
	std::cout << std::endl << std::endl;

}

//Displays the size of the word in underlined spaces
void DisplayCommands::DisplayWordSpaces(std::string chosenWord)
{
	for (int i = 0; i < chosenWord.size(); i++)
	{
		std::cout << "-";
		std::cout << " ";
	}
	std::cout << std::endl << std::endl;
}

