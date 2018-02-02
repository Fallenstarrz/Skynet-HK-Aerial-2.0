// Skynet-HK-Aerial-2.0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{

	cout << "Skynet HK-Aerial 2.0\nLets play a war game!" << endl << endl;
	do // This forces the player to play at least once. This is where we will restart the loop.
	{
		// We store our variables here, so they can reset every time we play again.
		srand(static_cast<unsigned int>(time(0))); // Seed random number generator
		int highNum = 64; // This is a variable to limit how high the grid goes
		int lowNum = 1; // This is a variable to limit how low the grid goes
		const int targetPos = rand() % highNum + lowNum; // This is the number that the AI is trying to find
		int randomAIPos = rand()%64; // randomAI's guess is held here
		int guess; // This is the number the AI is scanning
		int humanGuess; // Humans guess is held in this variable
		int ai1Tries = 0; // This variable holds the number of attempts it took binary search AI to find the target
		int ai2Tries = 0; // This variable holds the number of attempts it took linear search AI to find the target
		int ai3Tries = 0; // This variable holds the number of attempts it took random search AI to find the target
		int humanTries = 0; // This variable holds the number of attempts it took the player to find the target
		int winner; // This variable holds the number of attempts it took the winner to find the target
		char playAgain; // This variable holds the character the player inputs when asked if they would like to play again or not

		do // Do loop! This runs at least once! Human Guess
		{
			cout << "Where do you think the target is located (1-64)?" << endl; // Prompt user to enter their guess
			cin >> humanGuess; // This will get called every time the loop restarts. It will make the player choose a new guess.
			cout << "\nInitiating search at position " << humanGuess << "." << endl;

			if (humanGuess > targetPos) // if target is smaller than our guess
			{
				cout << "Target not found. \nYou must search a lower position." << endl << endl;
				humanTries++; // add 1 to tries, so we know how many attempts it took the player
			}
			else if (humanGuess < targetPos) // if target is larger than our guess
			{
				cout << "Target not found. \nYou must search a higher position." << endl << endl;
				humanTries++; // add 1 to tries, so we know how many attempts it took the player
			}
			else
			{
				humanTries++; // add 1 to tries, so we know how many attempts it took the player
				cout << "Target sighted at " << targetPos << endl; // print the block that we found our target at.
				cout << "Scanned " << humanTries << " blocks to find the target." << endl << endl; // Print the number of tries it took us to get the correct number
			}
		} while (humanGuess != targetPos); // This restarts the human guess loop

		do // Do loop! This runs at least once! Binary Search
		{
			guess = ((highNum - lowNum) / 2) + lowNum; // This will get called every time the loop restarts. It will make the computer choose a new guess.
			cout << "Initiating search at position " << guess << "." << endl;

			if (guess > targetPos)
			{
				cout << "Target not found. \nInitiating search at lower position." << endl << endl;
				highNum = guess; // If number is too high, then we make highNum the guess, so when we restart the loop, the computer cannot guess any higher than our previous number
				ai1Tries++; // add 1 to tries, so we know how many attempts it took the computer
			}
			else if (guess < targetPos)
			{
				cout << "Target not found. \nInitiating search at higher position." << endl << endl;
				lowNum = guess; // If number is too low, then we make lowNum the guess, so when we restart the loop, the computer cannot guess any lower than our previous guess
				ai1Tries++; // add 1 to tries, so we know how many attempts it took the computer
			}
			else
			{
				ai1Tries++; // add 1 to tries, so we know how many attempts it took the computer
				cout << "Target sighted at " << targetPos << endl; // print the block that we found our target at.
				cout << "Scanned " << ai1Tries << " blocks to find the target." << endl << endl; // Print the number of tries it took us to get the correct number

			}

		} while (guess != targetPos); // This is the loop part of the Do. As long as the AI hasn't found the target it will keep searching.

		for (int i = 0; i <= targetPos; i++) // Linear Search
		{
			if (i != targetPos) // if the iteration of our search is not equal to the targets position
			{
				cout << "Target not spotted at " << i << "." << endl;
			}
			else // if the iteration of our search is equal to the targets position
			{
				cout << "Target sighted at " << i << "." << endl;
				cout << "It took " << ai2Tries << " tries to find the target." << endl;
			}
			ai2Tries++; // add 1 to ai2's tries
		}

		while (true) // Random Search
		{
			ai3Tries++; // add 1 to ai3's tries
			if (randomAIPos != targetPos) // if the random AI's guess is not equal to the targets position
			{
				cout << "Target not found at " << randomAIPos << endl;
				randomAIPos = rand() % 64 + 1; // pick a new random number
			}
			else // if the random AI's guess is equl to the targets position
			{
				cout << "Target found at " << targetPos << endl;
				cout << "It took AI 3 " << ai3Tries << " tries to find the target." << endl;
				break; // break the loop when we have found the targets position
			}

		}
		system("cls"); // Clear Screen
		cout << "Binary search AI took " << ai1Tries << " to find the target." << endl; // results for binary
		cout << "Linear search AI took " << ai2Tries << " to find the target." << endl; // results for linear
		cout << "Random search AI took " << ai3Tries << " to find the target." << endl; // results for random
		cout << "Human Player took " << humanTries << " to find the target." << endl; // results for human

		winner = min(ai1Tries, min(ai2Tries, min(ai3Tries, humanTries))); // Sets the winner equal to the lowest number of tries so we can compare them next.

		// Below print out the name of the AI that won!
		if (winner == ai1Tries)
		{
			cout << "Binary Search AI 1 Wins!" << endl;
		}
		else if (winner == ai2Tries)
		{
			cout << "Linear Search AI 2 Wins!" << endl;
		}
		else if (winner == ai3Tries)
		{
			cout << "Random Search AI 3 Wins!" << endl;
		}
		else if (winner == humanTries)
		{
			cout << "Human Player 1 Wins!" << endl;
		}

		cout << "\n\nWould you like to play again?\nY/N" << endl;
		cin >> playAgain;
		while (playAgain != 'Y' && playAgain != 'N' && playAgain != 'y' && playAgain != 'n')
		{
			cout << "Error: Invalid Input.\nPlease Select a valid operator\n";
			cin >> playAgain;
		}
	} while (playAgain == 'y' || playAgain == 'Y');
	system("pause"); // Pause the console
	return 0;
}