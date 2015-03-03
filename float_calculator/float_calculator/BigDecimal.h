// Header file for BigDecimal Class

#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

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
    BigDecimal operator ++ ();
    BigDecimal operator ++(int);
    BigDecimal operator + (const BigDecimal);
    BigDecimal operator * (const BigDecimal);
};