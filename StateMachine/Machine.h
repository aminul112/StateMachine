/**
 * @file Machine.h
 * @author Aminul Chowdhury
 * @brief The class definition for Machine 
 * 
 * @version 0.1
 * @date 2021-07-05
 *
 * @copyright Copyright (c) 2021
 *
 */
#pragma once

#include "MachineStates.h"
#include "StartStopPauseTimer.h"
#include <map>
#include <set>
#include <mutex>

class AbstractState;

/**
 * @class Machine
 *
 * @brief The class definition for Machine. The state machine class which calls different
 * states to execute specific tasks,  prints data tables, adds user inputs to data table,
 * handles timer and few other things.
 *
 */
class Machine
{
    friend class AbstractState;

public:
    /**
     * @brief Generates 'first' N fibonacci numbers for a given N and save in to a set.
     *
     * @param resultFiboncciSet given set where results are saved
     * @param total how many numbers to generate.
     * @return
     */    
    Machine(unsigned int _output_period_in_seconds, std::map<int, int> &dataTableFrequencyMap_, StartStopPauseTimer *_timer, std::set<int> &_fiboncci_set);
    void getUserInput();
    void printDataTable();
    void printDataTableWithGoodByeMessage();
    void stopTimer();
    void pauseTimer();
    void startTimer();
    void isFiboncciNumber(int _fib_check);
    void addNumberToDataTableFrequencyMap(int number);
    ~Machine();

    // delete rule of 5 methods as not necessary
    Machine(const Machine &) = delete;
    Machine(Machine &&) = delete;
    Machine &operator=(const Machine &) = delete;
    Machine &operator=(Machine &&) = delete;

private:
    unsigned int outputPeriodInSeconds_;
    std::map<int, int> dataTableFrequencyMap_;
    std::set<int> firstThousandFiboncciSet_;
    StartStopPauseTimer *startStopPauseTimer_;
    std::unique_ptr<AbstractState> machineState_;
    std::mutex mutex_;
    

    void sortAndPrintData();
};