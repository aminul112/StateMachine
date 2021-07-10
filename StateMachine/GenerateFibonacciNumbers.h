/**
 * @file GenerateFibonacciNumbers.h
 * @author Aminul Chowdhury
 * @brief The class definition for GenerateFibonacciNumbers 
 * 
 * @version 0.1
 * @date 2021-07-05
 *
 * @copyright Copyright (c) 2021
 *
 */
#pragma once
#include <set>

/**
 * @class GenerateFibonacciNumbers
 *
 * @brief The class definition for GenerateFibonacciNumbers. This class provide a static funciton
 * which generates first N Fibonacci numbers as a set.
 *
 */

class GenerateFibonacciNumbers
{
public:
    /**
     * @brief Generates 'first' N fibonacci numbers for a given N and save in to a set.
     *
     * @param resultFiboncciSet given set where results are saved
     * @param total how many numbers to generate.
     * @return
     */
 static void generateFibonacciNumbersSet(
     std::set<unsigned long long> &resultFiboncciSet, int total);
};
