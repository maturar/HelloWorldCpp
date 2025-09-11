// A C++ program to demonstrate the use of constexpr 
#pragma once
#include<iostream>  
#include <string_view>

constexpr long int fib(int n)
{ 
    return (n <= 1) ? n : fib(n-1) + fib(n-2); 
}

class Fibonacci {
    public:
        void doExample () const
        { 
            constexpr std::string_view pre_text("The fibonacci of 30 is:\n");
            // value of res is computed at compile time. 
            constexpr long int res = fib(30);
            std::cout << pre_text << res << std::endl; 
        }
};


