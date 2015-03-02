#include <iostream>
#include "BigDecimal.h"
using namespace std;

int main()
{
    BigDecimal num;
    BigDecimal num2("1.2");
    
    cin >> num;
    
    if (num == num2)
        cout << "Matt is an asshole.\n";
    
    return 0;
}