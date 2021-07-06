/**
 * @file GenerateFibonacciNumbers.cpp
 * @author Aminul Chowdhury
 * @brief The file implements the GenerateFibonacciNumbers class. 
 * 
 * @version 0.1
 * @date 2021-07-05
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "GenerateFibonacciNumbers.h"

// Generates first N fibonacci numbers.
void GenerateFibonacciNumbers::generateFibonacciNumbersSet(std::set<int> &resultFiboncciSet, int total)
{

    int fib1 = 0;
    int fib2 = 1;
    int fib3 = 0;
    if (total == 1) {
        resultFiboncciSet.insert(0);
        return;
    }

    if (total == 2) {
        resultFiboncciSet.insert(0);
        resultFiboncciSet.insert(1);
        return;
    }
    total = total + 2;

    for (int i = 2; i < total; i++) {
        fib3 = fib1 + fib2;
        resultFiboncciSet.insert(fib3);
        fib1 = fib2;
        fib2 = fib3;
    }
}
