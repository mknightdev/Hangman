#include <iostream>
#include <Windows.h>
#include <stdlib.h> /* stand, rand */
#include <time.h> /* time */
#include <cstring> /* strcpy */

// function prototypes
void playGame();
int tutScr();
void quitGame();
int menuChoice();
void unknownWord(char[], char[]);
int guessWord(char, char[], char[]);
int playAgain();

// Global variables
const int g_maxLength = 80; // Maximum char length
bool g_repeat = true; // Menu repeat

int main()
{
	menuChoice();

	return 0;
}

void showMenu()
{
	system("CLS");
	// Welcome the user
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << " Welcome to Hangman!\n" << std::endl;
	std::cout << " Please select a menu: " << std::endl;
	std::cout << " 1. Play" << std::endl;
	std::cout << " 2. Instructions" << std::endl;
	std::cout << " 3. Exit" << std::endl;
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
}

int menuChoice()
{
	int m_option = 0;

	while (g_repeat)
	{
		do
		{
			system("CLS");
			showMenu(); // Show the menu first
			// Enter input
			std::cout << " >> ";
			std::cin >> m_option;
			

			switch (m_option)
			{
				// Play Game
			case 1:
			{
				system("CLS");
				playGame();
				break;
			}

			// Tutorial Screen
			case 2:
			{
				system("CLS");
				tutScr();
				break;
			}

			// Quit Game
			case 3:
			{
				system("CLS");
				quitGame();
				break;
			}

			default:
			{
				// Wrong input 
				system("CLS");
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
				std::cout << " Invalid Input." << std::endl;
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
				Sleep(1000);
				system("CLS");
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
				std::cout << " Invalid Input." << std::endl;
				std::cout << " Returning to menu." << std::endl;
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
				Sleep(1000);
				system("CLS");
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
				std::cout << " Invalid Input." << std::endl;
				std::cout << " Returning to menu.." << std::endl;
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
				Sleep(1000);
				system("CLS");
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
				std::cout << " Invalid Input." << std::endl;
				std::cout << " Returning to menu..." << std::endl;
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
				Sleep(1000);
				showMenu(); // Show menu again
			}
			}
		} while (m_option < 0 || m_option > 3);
	}

	system("PAUSE");
	return 0;
}

void playGame()
{
	int m_tries{ 6 }; // Number of attempts to guess correctly
	char m_word[g_maxLength]; // Random word to guess
	char m_hiddenWord[g_maxLength]; // Used to hide the word
	char m_letter; // User's guess

	// Array of words
	char m_fruit[][g_maxLength] = 
	{ "apple", "banana", "kiwi", 
	  "cherry", "blueberry", "orange",
	  "grapes", "peach", "mango",
	  "lime", "plum", "pear",
	  "strawberry", "pineapple", "apricot",
	  "melon"
	}; 
	srand(time(NULL)); // Generates a seed used to pick random word
	int m_randNum = rand() % 16;
	system("CLS");
	std::cout << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/" << std::endl;
	std::cout << " DEBUG! The random word is: " << m_fruit[m_randNum] << std::endl; // Picks and displays random word 
	std::cout << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n" << std::endl;

	strcpy_s(m_word, m_fruit[m_randNum]); // Copies the random word to another char - used for hiding the word
	unknownWord(m_word, m_hiddenWord); // Initialises the random word with #'s

	while (m_tries >= 0) // Whilst tries isn't 0, continue the loop
	{
		std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
		std::cout << " You have " << m_tries << " tries to guess the word!" << std::endl; // Display the user's guesses left
		std::cout << " Revealed: " << m_hiddenWord << std::endl; // Display the censored hidden word 
		std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n" << std::endl;
		std::cout << " Guess a letter: ";
		std::cin >> m_letter; // Asks for the user's guess 
		std::cin.clear();
		std::cin.ignore(10000, '\n');

		// If correct, fill the hidden word with the guessed letter
		// Otherwise, decrease the number of tries
		if (guessWord(m_letter, m_word, m_hiddenWord) == 0)
		{
			std::cout << "\n Wrong! That letter is not in the word" << std::endl;
			m_tries--; // Takes away from their max guesses
		}
		else
		{
			std::cout << "\n You found a letter!" << std::endl;
		}

		// Check if they've guessed the word and won
		if (strcmp(m_word, m_hiddenWord) == 0)
		{
			std::cout << "\n >> " << m_word << " << " << std::endl;
			std::cout << " Winner! You guessed the word!" << std::endl;
			break;
		}

		switch (m_tries)
		{
			case 6: // 6 tries left
			{

				std::cout << " _____________   " << std::endl;
				std::cout << " |       }       " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |______________ " << std::endl;

				break;
			}
			case 5: // 5 tries left
			{

				std::cout << " _____________   " << std::endl;
				std::cout << " |       }       " << std::endl;
				std::cout << " |       O       " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |______________ " << std::endl;

				break;
			}
			case 4: // 4 tries left
			{

				std::cout << " _____________   " << std::endl;
				std::cout << " |       }       " << std::endl;
				std::cout << " |       O       " << std::endl;
				std::cout << " |       |       " << std::endl;
				std::cout << " |       |       " << std::endl;
				std::cout << " |       |       " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |______________ " << std::endl;

				break;
			}
			case 3: // 3 tries left
			{

				std::cout << " _____________   " << std::endl;
				std::cout << " |       }       " << std::endl;
				std::cout << " |       O       " << std::endl;
				std::cout << " |       |       " << std::endl;
				std::cout << " |      /|       " << std::endl;
				std::cout << " |     / |       " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |______________ " << std::endl;

				break;
			}
			case 2: // 2 tries left
			{

				std::cout << " _____________   " << std::endl;
				std::cout << " |       }       " << std::endl;
				std::cout << " |       O       " << std::endl;
				std::cout << " |       |       " << std::endl;
				std::cout << " |      /|\\     " << std::endl;
				std::cout << " |     / | \\    " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |               " << std::endl;
				std::cout << " |______________ " << std::endl;

				break;
			}
			case 1: // 1 tries left
			{

				std::cout << " _____________   " << std::endl;
				std::cout << " |       }       " << std::endl;
				std::cout << " |       O       " << std::endl;
				std::cout << " |       |       " << std::endl;
				std::cout << " |      /|\\     " << std::endl;
				std::cout << " |     / | \\    " << std::endl;
				std::cout << " |      /        " << std::endl;
				std::cout << " |     /         " << std::endl;
				std::cout << " |______________ " << std::endl;

				break;
			}
			case 0: // GAME OVER
			{

				std::cout << " _____________   " << std::endl;
				std::cout << " |       }       " << std::endl;
				std::cout << " |       O       " << std::endl;
				std::cout << " |       |       " << std::endl;
				std::cout << " |      /|\\     " << std::endl;
				std::cout << " |     / | \\    " << std::endl;
				std::cout << " |      / \\     " << std::endl;
				std::cout << " |     /   \\    " << std::endl;
				std::cout << " |______________ " << std::endl;
				std::cout << "\n Game Over!" << std::endl;
				std::cout << "\n The word was: " << m_word << std::endl;

				m_tries = -1; // Failsafe 

				break;
			}
			default:
			{
				std::cout << " Error"; // If something fails, display an error
				break;
			}
		}
	}

	// After 3 seconds, clear the screen and ask the player if they want to play again
	std::cout << "\n Playing again in 3 seconds...";
	Sleep(3000);
	playAgain();
}

int playAgain()
{
	int m_playAgain;

	system("CLS");
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << " Would you like to play again?" << std::endl;
	std::cout << " 1. Yes" << std::endl;
	std::cout << " 2. No" << std::endl;
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << " >> ";
	std::cin >> m_playAgain; // Input

	switch (m_playAgain)
	{
		case 1: // Go to new round
		{
			playGame(); 
			break;
		}

		case 2: // Exits the game
		{
			g_repeat = false;

			system("CLS");
			std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
			std::cout << " Exiting the game." << std::endl;
			std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
			Sleep(1000);
			system("CLS");
			std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
			std::cout << " Exiting the game.." << std::endl;
			std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
			Sleep(1000);
			system("CLS");
			std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
			std::cout << " Exiting the game..." << std::endl;
			std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
			Sleep(1000);
			exit(1);
			break;
		}
		default:
		{
			std::cout << "Error" << std::endl;
			break;
		}
	}
	return 0;
}

void unknownWord(char _word[], char _hiddenWord[])
{
	int i;
	int m_length = strlen(_word); // Gets the length of the random word
	for (i = 0; i < m_length; i++)
	{
		_hiddenWord[i] = '#'; // Replaces each letter with a #
	}
	_hiddenWord[i] = '\0'; // Ends at the end of the char
	
}

// Fill in the hidden word
// 1: Input, 2: Random Word, 3: Hidden Word
int guessWord(char _guess, char _word[], char _hiddenWord[])
{
	int m_correct = 0;
	for (int i = 0; _word[i] != '\0'; i++) // Checks all letters until it reaches the end
	{
		// Checks to see if we guessed before
		if (_guess == _hiddenWord[i]) 
		{
			return 0; 
		}

		// Checks if the guess is in the hidden word
		if (_guess == _word[i])
		{
			_hiddenWord[i] = _guess; // Make the char of the hidden word our guess 
			m_correct++; // Increase if true
		}
	}
	return m_correct;
}

int tutScr()
{
	int m_tutOption; 

	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << " You must guess the hidden word within" << std::endl;
	std::cout << " 6 guesses, otherwise you lose the game." << std::endl;
	std::cout << "\n";
	std::cout << " Only one letter will count, so full word" << std::endl;
	std::cout << " guesses will take first letter of that word.\n" << std::endl;
	std::cout << " Enter 1 to return to menu." << std::endl;
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << " >> ";
	std::cin >> m_tutOption; // Input

	if (m_tutOption == 1)
	{
		g_repeat = true; // Continue the menu loop
		showMenu(); // Show menu options
	}

	return 0;
}

void quitGame()
{
	g_repeat = false; // Failsafe for stopping the loop

	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << " Exiting the game." << std::endl;
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	Sleep(1000);
	system("CLS");
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << " Exiting the game.." << std::endl;
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	Sleep(1000);
	system("CLS");
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << " Exiting the game..." << std::endl;
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	Sleep(1000);
	exit(1);
}