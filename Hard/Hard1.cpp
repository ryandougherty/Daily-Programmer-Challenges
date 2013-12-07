/*
 * Author: Ryan Dougherty
 *
 * Description:
 we all know the classic "guessing game" with higher or lower prompts. lets do a role reversal; you create a program that will 
 guess numbers between 1-100, and respond appropriately based on whether users say that the number is too high or too low. Try 
 to make a program that can guess your number based on user input and great code!
 
 *
 */

#include <iostream>

int main(int argc, char* argv[]) {
	int top=100, low=0, guess=0;
	int numGuesses = 1;
	bool isRunning = true;
	while (isRunning) {
		guess = (top+low)/2;
		char input;
		std::cout << "I guess " << guess << ". Am I high (1), low (2), or correct (3)?";
		std::cin >> input;
		switch (input) {
			case '1':
				top = guess;
				++numGuesses;
				break;
			case '2':
				low = guess;
				++numGuesses;
				break;
			case '3':
				isRunning = false;
				std::cout << "It only took " << numGuesses << " guesses to get your number!\n";
				break;
			default:
				std::cout << "Invalid input.\n";
				break;
		}
	}
}