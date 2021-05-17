// CalculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Calculator.h"

int main()
{
    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char oper = '+';
    Calculator c;

    std::cout << "Calculator Console Application\n\n";
    std::cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b\n";
 
    while (true)
    {
        std::cin >> x >> oper >> y;
        if (oper == '/' && y == 0)
        {
            std::cout << "Division by 0 exception\n";
            continue;
        }
        else
        {
            result = c.Calculate(x, oper, y);
            std::cout << "Result is: " << result << std::endl;
        }
    }

    return 0;
}