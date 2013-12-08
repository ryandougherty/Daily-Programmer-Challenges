/*
 * Author: Ryan Dougherty
 *
 * Description:
 Flavius Josephus was a roman historian of Jewish origin. During the Jewish-Roman wars of the first century AD, he was in a 
 cave with fellow soldiers, 41 men in all, surrounded by enemy Roman troops. They decided to commit suicide by standing in a 
 ring and counting off each third man. Each man so designated was to commit suicide. (When the count came back around the 
 ring, soldiers who had already committed suicide were skipped in the counting.) Josephus, not wanting to die, placed himself 
 in position #31, which was the last position to be chosen.
 
 In the general version of the problem, there are n soldiers numbered from 1 to n and each k-th soldier will be eliminated. 
 The count starts from the first soldier. Write a function to find, given n and k, the number of the last survivor. For 
 example, josephus(41, 3) = 31. Find josephus(123456789101112, 13).
 
 *
 */

#include <iostream>

typedef unsigned long long hard111Type;

hard111Type josephus(hard111Type, int);

int main(int argc, char* argv[]) {
	std::cout << "josephus(41, 3) last position is: " << josephus(41, 3) << "\n";
	std::cout << "josephus(123456789101112, 13) last position is: " << josephus(12345678910112ULL, 13) << "\n";
}

hard111Type josephus(hard111Type n1, int k) {
	if( n1 <= 1 ) return 1;
    hard111Type result = 1, n=2;
	
    if( k <= 1 ) {
        result = n1-1;
    } else while (n<n1) {
        hard111Type iterations = (n-1-result)/(k-1)+1;
        if( n+iterations > n1 ) iterations = n1 - n;
        result += k*iterations;
        n+=iterations;
        while( result >= n ) result-=(n-1) ;
    }
    return ( ( result + k - 1  ) % n1 ) + 1;
}