/*
 * Author: Ryan Dougherty
 *
 * Description:
 Checksums[2] are a tool that allow you to verify the integrity of data (useful for networking, security, error-correction, 
 etc.). Though there are many different Checksum algorithms, the general usage is that you give raw-data to your algorithm of 
 choice, and a block of data (usually smaller than the given data) is generated and can later be used by re-computing the 
 checksum and comparing the original and recent values.
 
 A classic example for how helpful Checksums are is with data-networking: imagine you have a packet of information that must 
 be guaranteed the same after receiving it. Before sending the data, you can compute its checksum, and send both blocks 
 together. When received, the data can be used to re-compute a checksum, and validate that the given checksum and your own 
 checksum are the same. The subject is much more complex, since there are issues of data-entropy[3] and the importance of the 
 checksum's size compared to the raw data size.
 
 This example is so common in network programming, one of the basic Internet networking protocols (TCP)[4] has it built-in!
 
 Your goal will be more modest: you must implement a specific checksum algorithm (Fletcher's 16-bit Checksum[5] ) for given 
 lines of text input. The C-like language pseudo-code found on Wikipedia[6] is a great starting point!
 
 Note: Make sure to explicitly implement this algorithm, and not call into other code (libraries). The challenge here is 
 focused on your implementation of the algorithm.
 
 * Formal Inputs & Outputs
 
 * Input Description:
 On standard console input, you will first be given an integer N which ranges inclusively from 1 to 256. After this line, you 
 will receive N-lines of ASCII text. This text will only contain regular printable characters, and will all be on a single 
 line of input.
 
 * Output Description:
 For each line of input, print the index (starting from 1) and the 16-bit Fletcher's checksum as a 4-digit hexadecimal number.
 
 * Sample Input:
 3
 Fletcher
 Sally sells seashells by the seashore.
 Les chaussettes de l'archi-duchesse, sont-elles seches ou archi-seches ?
 
 * Sample Output:
 1 D330
 2 D23E
 3 404D
 
 *
 */

#include <fstream>
#include <iostream>
#include <vector>

uint16_t Fletcher16(std::string data);

int main(int argc, char* argv[]) {
	std::ifstream inFile(argv[1]);
	if (!inFile) {
		std::cout << "Invalid num of parameters!";
		return EXIT_FAILURE;
	}
	int num;
	inFile >> num;
	
	std::string line;
	std::vector<uint16_t> vec;
	
	while (std::getline(inFile, line)) {
		if (line.size() != 0)
			vec.push_back(Fletcher16(line));
	}
	
	int index = 1;
	std::for_each(vec.begin(), vec.end(), [&](uint16_t n) {
		std::cout << std::dec << index << " " << std::hex << n << "\n";
		++index;
	});
}

uint16_t Fletcher16(std::string data) {
	uint16_t sum1 = 0, sum2 = 0;
	for (const auto& i : data) {
		sum1 = (sum1+i)%255;
		sum2 = (sum2+sum1)%255;
	}
	return (sum2 << 8) | sum1;
}