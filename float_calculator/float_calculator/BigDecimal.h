#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

const static string lessThanTwenty[] = {"one", "two", "three", "four", "five",
                                        "six", "seven", "eight", "nine", "ten",
                                        "eleven", "twelve", "thirteen", "fourteen",
                                        "fifteen", "sixteen", "seventeen", "eighteen"
                                        "nineteen" };

const static string tens[] = {"ten", "twenty", "thirty", "forty"
                              "fifty", "sixty", "seventy", "eighty",
                              "ninety"};

class BigDecimal
{
private:
    string integer;
    string decimal;
public:
    BigDecimal();
    BigDecimal(string s);
    BigDecimal(string i, string d);
    ~BigDecimal();
    double toDouble() const;
    friend ostream &operator << (ostream &, BigDecimal);
    friend istream &operator >> (istream &, BigDecimal&);
    bool operator == (const BigDecimal);
    bool operator != (const BigDecimal);
  
};