/*
 * Author: Ryan Dougherty
 *
 * Description:
 BrainFuck, is a Turing-complete (i.e. computationally-equivalent to modern programming languages), esoteric programming
 language. It mimics the concept of a Turing machine[3] , a Turing-complete machine that can read, write, and move an 
 infinite tape of data, through the use of the language's eight (that's right: 8!) operators.
 
 An example is:
 ++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.
 Which prints "Hello World!"
 Your goal is to write a BrainFuck interpreter from scratch, and have it support both single-character output to 
 standard-out and single-character input from standard-in.
 
 * Formal Inputs & Outputs
 
 * Input Description:
 String BFProgram - A string of a valid BrainFuck program.
 
 * Output Description:
 Your function must execute and print out any data from the above given BrainFuck program.
 
 * Sample Input:
 -0.5 0 0.5 0
 
 * Sample Output:
 See above
 
 * Notes:
 This is a trivial programming challenge if you understand the basis of a Turing-machine. I strongly urge you to read all 
 related Wikipedia articles to prepare you for this. A more significan't challenge would be to write a BF interpreter 
 through the BF language itself.
 
 *
 */

#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
	std::ifstream inFile(argv[1]);
	if (!inFile) {
		std::cerr << "Invalid num of parameters!";
		return EXIT_FAILURE;
	}
	std::vector<u_char> tape(1);
	std::vector<size_t> openBrackets;
	std::string instructions;
	inFile >> instructions;
	
	size_t idx = 0;
	auto ptr = tape.begin();
	while (idx < instructions.size()) {
		switch (instructions[idx]) {
			case '+':
				++(*ptr);
				break;
			case '-':
				--(*ptr);
				break;
			case '.':
				std::cout << *ptr;
				break;
			case '<':
				if (ptr == tape.begin()) {
					std::cerr << "Cannot move left of beginning of tape\n";
					return EXIT_FAILURE;
				} else {
					--ptr;
				}
				break;
			case '>':
				++ptr;
				if (ptr == tape.end()) {
					tape.push_back(0);
					ptr = --tape.end();
				}
				break;
						case ',':
				std::cin >> *ptr;
				break;
			case '[':
				if (*ptr == 0) {
					int opens = 0;
					while (opens >= 0) {
						++idx;
						switch (instructions[idx]) {
							case '[':
								++opens;
								break;
							case ']':
								--opens;
								break;
						}
					}
				} else {
					openBrackets.push_back(idx);
				}
				break;
			case ']':
				if (*ptr)
					idx = openBrackets.back();
				else
					openBrackets.pop_back();
				break;
		}
		++idx;
	}
}