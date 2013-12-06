/* 
 * Author: Ryan Dougherty
 *
 * Description:
 * create a program that will ask the users name, age, and reddit username. have it tell them the information back, in the format:
 * your name is (blank), you are (blank) years old, and your username is (blank)
 * for extra credit, have the program log this information in a file to be accessed later.
 *
 */

#include <fstream>
#include <iostream>
#include <string>

const char* fileLocation = "file.txt";

int main() {
	std::ifstream inFile(fileLocation);
	if (inFile) {
		std::cout << &inFile;
		return EXIT_SUCCESS;
	}
	std::string name, yearsOld, username, stringToWrite;
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Enter how old you are: ";
	std::cin >> yearsOld;
	std::cout << "Enter your username: ";
	std::cin >> username;
	stringToWrite += "your name is " + name + ", you are " + yearsOld + " years old, and your username is " + username;
	
	std::cout << stringToWrite;
	std::ofstream outFile(fileLocation);
	outFile << stringToWrite;
}