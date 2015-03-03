#include <iostream>
#include "BigDecimal.h"
using namespace std;

int main()
{
    BigDecimal num("100000.2");
    BigDecimal num2("1.8");
    
    BigDecimal num3 = num + num2;
    
    return 0;
}