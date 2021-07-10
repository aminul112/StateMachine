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
#include <iostream>

// Generates first N fibonacci numbers.
void GenerateFibonacciNumbers::generateFibonacciNumbersSet(

    /*
    Note: My program will not support up to 1000th fibonacci number
    as no standard data type will fit this large number.
    We need to implement big integer class to support big string 
    addition.
    */
    std::set<unsigned long long> &resultFiboncciSet, int total) {

    unsigned long long fib1(0);
    unsigned long long fib2 (1);
    unsigned long long fib3;
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
        std::cout << fib3 << "  " << i << std::endl;
    }
    
}
