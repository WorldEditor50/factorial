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
LargeInt fibonacci(int n)
{
    if (n == 0) {
        return std::string("0");
    }
    if (n == 1) {
        return std::string("1");
    }
    /* 0, 1, 2, 3, 5, 8, 13, 21*/
    LargeInt x1 = 0;
    LargeInt x2 = 1;
    LargeInt x3 = 0;
    for (int i = 1; i < n; i++) {
        x3 = x1 + x2;
        x1 = x2;
        x2 = x3;
    }
    return x3;
}

int main()
{
    LargeInt x1 = 999;
    LargeInt x2 = 111;
    LargeInt x3 = x1 * x2;
    std::cout<<x1.toString()<<std::endl;
    std::cout<<x2.toString()<<std::endl;
    std::cout<<x3.toString()<<std::endl;
    std::cout<<"fibo:"<<std::endl;
    LargeInt x4 = fibonacci(100);
    std::cout<<x4.toString()<<std::endl;
    std::cout<<"factorial:"<<std::endl;
    LargeInt x5 = factorial(100);
    std::cout<<x5.toString()<<std::endl;
    return 0;
}
