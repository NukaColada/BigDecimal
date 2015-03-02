//
//  BigDecimal.cpp
//  float_calculator
//
//  Created by Austine Shughart on 2/22/15.
//  Copyright (c) 2015 Austine Shughart. All rights reserved.
//

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

int BigDecimal::operator + (const BigDecimal right)
{
    int realSum = stoi(integer) + stoi(right.integer); // Holds initial integer sum
    
    int decSum = stoi(decimal) + stoi(right.decimal);
    
    if (decSum > 100)
    {
        decSum -= 100;
        realSum++;
    }
    
    
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

