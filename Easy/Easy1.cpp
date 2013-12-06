#include <iostream>
#include <string>

int main() {
	std::string name, yearsOld, username;
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Enter how old you are: ";
	std::cin >> yearsOld;
	std::cout << "Enter your username: ";
	std::cin >> username;
	std::cout << "your name is " << name << ", you are " << yearsOld << " years old, and your username is " << username;
}