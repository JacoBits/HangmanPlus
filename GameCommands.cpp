#include "GameCommands.h"

//Initializes the values held in the difficulty structures
void GameCommands::InitializeDifficultySettings()
{
	hard.totalAttempts = 9;
	challenge.totalAttempts = 7;
	impossible.totalAttempts = 6;

	challenge.displaySpaces = false;
	impossible.displaySpaces = false;

	impossible.displayRepeated = false;

	regular.wordBank = { "chair", "balloon", "create", "send", "program", "caption", "kitten", "triangle", "square", "circle", "bold", "screen", "late", "mermaid", "animal", "racecar", "oval", "side", "crawl", "salt", "pepper", "brow", "hop", "word", "tablet" };

	hard.wordBank = { "clip", "spark", "program", "caption", "kraken", "cake", "triangle", "bond", "seven", "mermaid", "antenna", "astronaut", "jolly", "lighter", "corruption", "letter", "computation", "why", "octopus", "ambience", "triage", "hello", "wood", "tree", "sandwich" };

	challenge.wordBank = { "rhythm", "send", "palindrome", "eclipse", "cymbal", "nymph", "whirlwind", "kraken", "jolly", "voltage", "key", "simple", "why", "octopus", "ambience", "triage", "hello", "wood", "tree", "sandwich" };

	impossible.wordBank = { "rhythm", "jazz", "esternocleidomastoideo", "myrrh", "palindrome", "eclipse", "cymbal", "nymph", "whirlwind", "kraken", "jolly", "voltage",  "screen", "late", "mermaid", "animal", "racecar", "oval" };
}

//Returns a pointer to the difficulty the user choses
void GameCommands::SelectDifficulty()
{
	char difficultyChosen;
	bool validInput = true;

	do {
		std::cout << "Input the first letter of the difficulty you wish to play" << std::endl;
		std::cin >> difficultyChosen; 
		std::cin.ignore(512, '\n');
		std::cout << "Selected ";
		switch (difficultyChosen)
		{
		case 'R':
		case 'r':
			std::cout << "regular mode" << std::endl;
			validInput = true;
			chosenDifficulty = &regular;
			break;
		case 'H':
		case 'h':
			std::cout << "hard mode" << std::endl;
			validInput = true;
			chosenDifficulty = &hard;
			break;
		case 'C':
		case 'c':
			std::cout << "challenge mode" << std::endl;
			validInput = true;
			chosenDifficulty = &challenge;
			break;
		case 'I':
		case 'i':
			std::cout << "impossible mode" << std::endl;
			std::cout << "Good luck, player.... ;)" << std::endl;
			validInput = true;
			chosenDifficulty = &impossible;
			break;
		default:
			std::cout << "invalid, please ";
			validInput = false;
		}

	} while (!validInput);
}

//Chooses the word that is going to be played (all difficulties), it also separates all the characters in that word into a vector called lettersInWord
void GameCommands::PickAWord()
{
	attemptsLeft = chosenDifficulty->totalAttempts;
	
	srand((unsigned int)time(NULL));
	int chosenIndex = (rand() % chosenDifficulty->wordBank.size());

	chosenWord = chosenDifficulty->wordBank[chosenIndex];

	guessedLetters.resize(chosenWord.length());
	std::fill(guessedLetters.begin(), guessedLetters.end(), ' ');

	for (char letter : chosenWord)
		lettersInWord.push_back(letter);

}

//Asks the user to input a letter, and determines if the user's input is valid. 
//A valid input is a letter or "!". If it's "!", the program asks the user to input a word.
void GameCommands::GetUserInput()
{
	bool validInput = false;

	do {
		std::cout << "Input a letter (input ! to guess the word): ";
		std::cin >> userGuess;

		userGuess = tolower(userGuess);

		std::cin.ignore(512, '\n');
		std::cout << std::endl;

		//cout << "Letter input: " << userGuess << endl; (debugging)

		validInput = ValidateUserInput();
	} while (!validInput);
}

//Checks if the user input a letter or "!", and that the letter is not a repeat guess. Returns true if the guess is valid
bool GameCommands::ValidateUserInput()
{
	bool isValidInput = false;

	if (isalpha(userGuess))
	{
		isValidInput = !CheckRepeatedGuess();

	}
	else if (userGuess == '!') {

		isValidInput = ValidateWordInput();
		if (!isValidInput)
			std::cout << "Invalid guess, please input a word" << std::endl;

	}
	else
		std::cout << "Invalid guess, please input a letter" << std::endl;

	return isValidInput;
}

//Checks if the letter the user input has been input before. Returns true if the letter is a repeated guess
bool GameCommands::CheckRepeatedGuess()
{
	bool repeatedLetter = false;

	if (!chosenDifficulty->displayRepeated)
		return false;

	for (char letter : usedLetters)
	{
		//cout << "comparing " << userGuess << " and " << letter << endl; (debugging)

		if (userGuess == letter)
			repeatedLetter = true;
	}

	if (!repeatedLetter)
	{
		usedLetters.push_back(userGuess);
		return false;
	}
	else {
		std::cout << "This letter has already been used, please input another letter" << std::endl;
		std::cout << "Used letters: ";
		for (char letter : usedLetters)
			std::cout << letter << " ";
		std::cout << std::endl;
		return true;
	}
}

//Checks if the word the user is guessing is a valid word (only made up of letters). Returns true if the word is valid
bool GameCommands::ValidateWordInput()
{
	std::cout << "What is the word? ";
	std::cin >> guessWord;
	std::cout << std::endl;
	for (char& letter : guessWord)
	{
		if (!isalpha(letter))
			return false;
		else
			letter = tolower(letter);
	}
	return true;
}

//Determines if the letter the user input is in the word. Also determines the position(s) of the letter in the word, or how many of that letter there are in the word, depending on difficulty
void GameCommands::IsLetterInWord()
{
	size_t guessPosition;
	int counter = 0;

	if (chosenWord.find(userGuess) != std::string::npos)
	{

		if (!chosenDifficulty->displaySpaces)
		{
			for (int j = 0; j < guessedLetters.size(); j++)
				guessedLetters.at(j) = 'X';


			for (int i = 0; i < chosenWord.length(); i++)
			{
				if (chosenWord[i] == userGuess)
					counter++;
			}


			std::cout << "The word contains ";
			if (chosenDifficulty->displayRepeated)
				std::cout << counter << " ";

			std::cout << userGuess << std::endl;
		}
		else
		{
			guessPosition = chosenWord.find(userGuess);
			guessedLetters.at(guessPosition) = userGuess;

			while (chosenWord.find(userGuess, guessPosition + 1) != std::string::npos)
			{
				guessPosition = chosenWord.find(userGuess, guessPosition + 1);
				guessedLetters.at(guessPosition) = userGuess;
			}
		}
		/*for (size_t position : letterPositions)
			cout << position << " ";
		cout << endl;*/
	}
	else if (userGuess != '!')
		attemptsLeft--;
		//cout << "The word does not contain " << userGuess << endl;
}

//Checks if the word has been guessed by the user, whether by guessing all the letters in the word, or by guessing the word directly
//It compares the vectors guessedLetters and lettersInWord to determine if the user has input all the letters in the word
bool GameCommands::CheckIfWordGuessed()
{
	if (lettersInWord == guessedLetters)
		return true;

	if (guessWord == chosenWord)
	{
		for (char letter : chosenWord)
		{
			std::cout  << letter;
			std::cout << " ";
		}
		std::cout << std::endl;
		for (char letter : chosenWord)
		{
			std::cout << "-";
			std::cout << " ";
		}
		std::cout << std::endl;

		return true;


	}
	else if (guessWord != " ") {
		std::cout << "Wrong word" << std::endl;
		attemptsLeft -= 2; //change for each difficulty ADD
		guessWord = " ";
		return false;
	}

	return false;
}

//Checks if the game has ended because the user has 0 guesses left or less
bool GameCommands::CheckIfGameOver()
{
	if (attemptsLeft <= 0)
	{
		std::cout << "The word was: " << chosenWord << std::endl;
		std::cout << std::endl << std::endl << std::endl;
		std::cout << "GAME OVER" << std::endl;
		return true;
	}
	else
		return false;

}

