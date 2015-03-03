/*
Austine Shughart
Email: ats5263@psu.edu
CMPSC 122
Assignment 2


This program 
*/

#include <iostream>
#include "BigDecimal.h"
using namespace std;

int main()
{
    BigDecimal num("100000.2");
    BigDecimal num2("1.8");
    
    BigDecimal num3 = num + num2;
    
    cout << num3 << endl;
    
    return 0;
}