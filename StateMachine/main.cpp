#include "Machine.h"
#include "MachineStates.h"
#include "GenerateFibonacciNumbers.h"
#include "StartStopPauseTimer.h"
#include <iostream>
#include <map>
#include <set>



int main()
{

    int outputPeriodInSeconds, firstNumber;
    std::map<int, int> dataTableFrequencyMap;
    std::set<int> firstThousandFiboncciSet;
   
    GenerateFibonacciNumbers::generateFibonacciNumbersSet(firstThousandFiboncciSet, 1000);

    std::cout << "Please enter the output period:";
    std::cin >> outputPeriodInSeconds;

    std::cout << "Please enter the first number:";
    std::cin >> firstNumber;
    dataTableFrequencyMap[firstNumber] = 1;

    StartStopPauseTimer timerFtr;

    Machine stateMachineFtr(outputPeriodInSeconds, dataTableFrequencyMap, &timerFtr, firstThousandFiboncciSet);
    
    // sleep for 100 milliseconds
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::thread dataTablePrinterInBackgroundThread(&Machine::printDataTable, &stateMachineFtr);
    
    stateMachineFtr.getUserInput();

    dataTablePrinterInBackgroundThread.detach();

    return 0;
}
