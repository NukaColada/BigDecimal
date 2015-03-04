/*
Austine Shughart
Email: ats5263@psu.edu
CMPSC 122
Assignment 2

This program utilizes string objects to perform math functions
with long decimal numbers.
*/

#include <iostream>
#include "BigDecimal.h"
using namespace std;

int main()
{
	BigDecimal num1("56.8"),
		       num2("1.5"),
		       num3("3.14159"),
		       num4;

	// Showing math and insertion operator
	cout << num1 << " plus " << num2 << " equals " << num1 + num2 << endl;
	cout << num1 << " times " << num3 << " equals " << num1 * num3 << endl;

	// Demonstrate extraction operator
	cin >> num4;
    
    // Show input in console
    cout << "You entered " << num4 << endl;
    
    // new variable to show incrementation
	BigDecimal num5("42.1");

	// Increment operators
	cout << "Increment prefix: " << ++num5 << endl;
	cout << "Increment postfix: " << num5++ << endl;

	// Converting to double
	double x = num5.toDouble();
	cout << "Double x equals " << x << endl;

		
	return 0;
}
