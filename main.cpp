#include <iostream>
#include <cmath>
#include "largeint.h"

LargeInt factorial(int n)
{
    LargeInt x("1");
    for (int i = 1; i < n + 1; i++) {
        x = x * LargeInt(i);
    }
    return x;
}
int main()
{
    LargeInt x1 = 999;
    LargeInt x2 = 1001;
    LargeInt x3 = x1 * x2;
    std::cout<<x1.toString()<<std::endl;
    std::cout<<x2.toString()<<std::endl;
    std::cout<<x3.toString()<<std::endl;
    LargeInt x4 = factorial(100);
    std::cout<<x4.toString()<<std::endl;
    return 0;
}
