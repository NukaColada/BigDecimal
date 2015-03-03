// Specification file for the BigDecimal class

#include "BigDecimal.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

// Default constructor sets string variables to 0.0
BigDecimal::BigDecimal()
{
    integer = "0";
    decimal = ".0";
}

// Second constructor accepts a single string, then separates
// the integer and decimal parts and stores them in separate string
// variables
BigDecimal::BigDecimal(string s)
{
    unsigned long size = s.length();
    unsigned long decLocation = s.find('.', 0);
    integer = s.substr(0, decLocation);
    decimal = s.substr(decLocation + 1, size);
}

// Third constructor accepts the integer and decimal separately
BigDecimal::BigDecimal(string i, string d)
{
    integer = i;
    decimal = d;
}

// Method to convert a BigDecimal object to a double
double BigDecimal::toDouble() const
{
    string toDouble;
    
    // Create new string with both decimal and integer strings
    toDouble = integer;
    toDouble.append(".");
    toDouble.append(decimal);
    
    // Convert combined string to a double
    double num = stod(toDouble);
    
    return num;
}

// Overloading the equality operator
bool BigDecimal::operator == (const BigDecimal right)
{
    if (integer == right.integer && decimal == right.decimal)
        return true;
    
    return false;
}

bool BigDecimal::operator != (const BigDecimal right)
{
    if (integer == right.integer && decimal == right.decimal)
        return false;
    
    return true;
}

BigDecimal BigDecimal::operator + (const BigDecimal right)
{
    BigDecimal tmp; // Object to be returned
    
    string leftTmp = decimal,
           rightTmp = right.decimal;
    
    // Process for adding the decimal part first
    
    int leftTmpLength = leftTmp.length(), // Hold lengths of the two decimal strings
        rightTmpLength = rightTmp.length();
    
    int tmp1, tmp2,
        carry = 0; // Used in actual math operation
    
    // Ensures that both strings are the same length
    while (leftTmpLength > rightTmpLength)
    {
        rightTmp += "0";
        rightTmpLength++;
    }
    
    // Check both ways
    while (leftTmpLength < rightTmpLength)
    {
        leftTmp += "0";
        leftTmpLength++;
    }
    
    // Begin with an empty string in return object's decimal string
    // to avoid junk data
    tmp.decimal = "";
    
    
    for (int i = (leftTmpLength - 1); i >= 0; i--)
    {
        tmp1 = leftTmp[i] - '0';
        tmp2 = rightTmp[i] - '0';
        tmp.decimal = string(1,(((tmp1 + tmp2 + carry) % 10) + '0')) + tmp.decimal;
        if ((tmp1 + tmp2 + carry) >= 10)
            carry = 1;
        else
            carry = 0;
    }
    
    // Repeat process again for integer string
    
    leftTmp = integer;
    rightTmp = right.integer;
    
    leftTmpLength = leftTmp.length();
    rightTmpLength = rightTmp.length();
    
    while(leftTmpLength > rightTmpLength)
    {
        rightTmp = "0" + rightTmp;
        rightTmpLength++;
    }
    
    while (leftTmpLength < rightTmpLength)
    {
        leftTmp = "0" + leftTmp;
        leftTmpLength++;
    }
    
    // Set integer variable to empty string to avoid garbage
    tmp.integer = "";
    
    for (int i = (leftTmpLength - 1); i >= 0; i--)
    {
        tmp1 = leftTmp[i] - '0';
        tmp2 = rightTmp[i] - '0';
        
        tmp.integer = string(1, (((tmp1 + tmp2 + carry) % 10) + '0')) + tmp.integer;
        
        if ((tmp1 + tmp2 + carry) >= 10)
            carry  = 1;
        else
            carry = 0;
    }
    
    if (carry >= 1)
        tmp.integer = string(1, ((carry) + '0')) + tmp.integer;
    
    return tmp;
}

BigDecimal BigDecimal::operator * (const BigDecimal right)
{
    BigDecimal tmp;
    
    string leftSide,
           rightSide,
           final;
    int leftDecLength,
        rightDecLength;
    
    
    int decimalPlace,
        finalLength,
        leftLen,
        rightLen,
        leftInt,
        rightInt,
        multiply;
    
    // Get length of decimal strings
    leftDecLength = decimal.length();
    rightDecLength = right.decimal.length();
    
    // Figure out where the new decimal should be based on the string lengths
    decimalPlace = leftDecLength + rightDecLength;
    leftLen = leftSide.length();	
    rightLen = rightSide.length();
    
    
    // Fills in space if one string is longer than the other
    while (rightLen > leftLen)
    {
        leftSide = "0" + leftSide;
        leftLen++;
    }
    
    // Check reverse length
    while (rightLen < leftLen)
    {
        rightSide = "0" + rightSide;
        rightLen++;
    }
    
    
    leftSide = integer + decimal;	
    rightSide = right.integer + right.decimal;
    
    // Convert integer string to an int variable
    leftInt = stoi(leftSide);	
    rightInt = stoi(rightSide);
    
    // Multiply integers
    multiply = leftInt * rightInt;
    
    // Convert back to string
    final = to_string(multiply);
    finalLength = final.length();
    
    // Assign final values to strings
    integer = final.substr(0, finalLength - decimalPlace);
    decimal = final.substr(finalLength - decimalPlace, finalLength);
    
    // Assign calculated values to temporary object
    tmp.integer = integer;	
    tmp.decimal = decimal;

    
    return tmp;
}

// Overloading the prefix increment operator
BigDecimal BigDecimal::operator ++ ()
{
    int temp = stoi(integer); // Create temporary integer variable
    temp += 1; // Add one to variable
    integer = to_string(temp); // Convert back to string
    
    return *new BigDecimal(integer, decimal); // Return a new BigDecimal object
}

// Overloading the postfix increment operator
BigDecimal BigDecimal::operator ++ (int)
{
    BigDecimal temp(integer, decimal); // Create temporary object to hold values
    int intTemp = stoi(integer); // Convert current int string to integer
    intTemp += 1; // Increment the integer string
    integer = to_string(intTemp); // Convert back to string
    
    return temp; // Return temporary object
}


// Overloading the insertion operator to display a BigDecimal object
ostream &operator << (ostream &outStream, BigDecimal num)
{
    outStream << num.integer << "." << num.decimal;
    return outStream;
}

// Overloaded extraction operator to get BigDecimal input by using
// the cin function
istream &operator >> (istream &inStream, BigDecimal &num)
{
    string input;
    
    cout << "Enter a number: ";
    getline(inStream, input);
    
    unsigned long size = input.length();
    unsigned long decLocation = input.find('.', 0);
    num.integer = input.substr(0, decLocation);
    num.decimal = input.substr(decLocation + 1, size);
    
    return inStream;
}



BigDecimal::~BigDecimal()
{
}

