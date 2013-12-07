/*
 * Author: Ryan Dougherty
 *
 * Description:
 Computing the volume of a circle is pretty straight-forward: Pi x Radius x Radius, or simply Pi x r 2.
 What if we wanted to computer the volume of two circles? Easy, just sum it! Yet, what about two intersecting circles, much like the classic Venn diagram?
 Your goal is to write a program that takes two unit-circles (radius of one) at given locations, and compute that shape's volume. You must make sure to not double-count the intersecting volume! (i.e. you must not sum this red area twice).
 As a starting point, check out how to compute circle segments.
 
 * Formal Inputs & Outputs
 
 * Input Description:
 On standard input you will be given four floating-point space-delimited values: x y u w. x and y are the first circle's position in Cartesian coordinates. The second pair u and w are the second circle's position.
 Note that the given circles may not actually intersect. If this is the case, return the sum of both circles (which will always be Pi x 2 since our circles are unit-circles).
 
 * Output Description:
 Print the summed volume of the two circles, up to an accuracy of 4 digits after the decimal place.
 
 * Sample Input:
 -0.5 0 0.5 0
 
 * Sample Output:
 5.0548
 
 *
 */

#include <cmath>
#include <fstream>
#include <iostream>

// file is argv[1]
int main(int argc, char* argv[]) {
	std::ifstream inFile(argv[1]);
	if (!inFile) {
		std::cout << "Invalid num of parameters!";
		return EXIT_FAILURE;
	}
	double x1, x2, y1, y2;
	inFile >> x1 >> y1 >> x2 >> y2;
	double d = sqrt(pow(x2-x1, 2) + pow(y2-y1,2)); // distance between centers
	if (d > 1) {
		std::cout << 2*M_PI << "\n";
		return EXIT_SUCCESS;
	}
	double A = 2*acos(d/2.0) - 0.5*d*sqrt(4-pow(d,2)); // well known formula for area
	std::cout << 2*M_PI-A << "\n";
}