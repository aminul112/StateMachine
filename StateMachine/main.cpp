/**
 * @file main.cpp
 * @author Aminul Chowdhury
 * @brief This file implements the main functions. 
 * 1. Take inputs from user.
 * 2. It creates object for timer and generates fibonacci numbers. 
 * 3. Then passes these 2 items to create a state machine.Which sets RunState as initial state.
 * 4. Goes to sleep for 100 milliseconds. ( could be used conditiona variable)
 * 5. Create a new thread to print datatable in the backgorund.
 * 6. Ask for user input and machine coninues to run.
 * 7. Detach the printing thread. 
 * 
 * @version 0.1
 * @date 2021-07-05
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "Machine.h"
#include "MachineStates.h"
#include "GenerateFibonacciNumbers.h"
#include "StartStopPauseTimer.h"
#include <iostream>
#include <map>
#include <set>

const unsigned int TOTAL_FIBONACCI_NUMBERS_REQUIRED = 1000;



int main()
{
  try {
    int outputPeriodInSeconds, firstNumber;
    std::map<int, int> dataTableFrequencyMap;
    std::set<unsigned long long> firstThousandFiboncciSet;

    // First generate fibonacci numbers and send it as depenedency
    GenerateFibonacciNumbers::generateFibonacciNumbersSet(
        firstThousandFiboncciSet, TOTAL_FIBONACCI_NUMBERS_REQUIRED);

    // Get basic user inputs
    std::cout << "Please enter the output period:";
    std::cin >> outputPeriodInSeconds;

    std::cout << "Please enter the first number:";
    std::cin >> firstNumber;
    dataTableFrequencyMap[firstNumber] = 1;

    StartStopPauseTimer timerFtr;

    // Create a machine object with all dependencies
    Machine stateMachineFtr(outputPeriodInSeconds, dataTableFrequencyMap,
                            &timerFtr, firstThousandFiboncciSet);

    // sleep for 100 milliseconds
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // create printing thread
    std::thread dataTablePrinterInBackgroundThread(&Machine::printDataTable,
                                                   &stateMachineFtr);

    // This will basically start the machine and allow switchig between states.
    stateMachineFtr.getUserInput();

    // detach printing thread
    dataTablePrinterInBackgroundThread.detach();

    
  } catch (...) {
    std::cout << "Exception Happened at execution exiting" << std::endl;
  }

    return 0;
}
