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
     * @brief Constructor to set all dependencies.
     *
     * @param _output_period_in_seconds to set after how many seconds data table should be printed
     * @param _dataTableFrequencyMap data table frequency map, initially filled with one number and passed
     * @param _timer  timer class pointer
     * @param _fiboncci_set a set of first 1000 fibonacci numbers
     */    
    Machine(unsigned int _output_period_in_seconds,
         std::map<int, int> &_dataTableFrequencyMap,
         StartStopPauseTimer *_timer, std::set<unsigned long long> &_fiboncci_set);
   
    /**
     * @brief get input from user.
     *
     */
    void getUserInput();
    
    /**
     * @brief Print data table periodically if not in paused state.
     *
     */
    void printDataTable();
   
    /**
     * @brief Print data table before exiting with a good bye message.
     *
     */
    void printDataTableWithGoodByeMessage();

    /**
     * @brief A wrapper function to call stop() function of timer object.
     *
     */
    void stopTimer();

    /**
     * @brief A wrapper function to call pause() function of timer object.
     *
     */
    void pauseTimer();

    /**
     * @brief A wrapper function to call start() function of timer object.
     *
     */
    void startTimer();

    /**
     * @brief To check if a given number is a fibonacci or not.
     *
     */
    void isFiboncciNumber(unsigned long long _fib_check);

    /**
     * @brief To add a number in the ferquency data table.
     *
     */
    void addNumberToDataTableFrequencyMap(int number);
    ~Machine();

    // delete rule of 5 methods as not necessary
    Machine(const Machine &) = delete;
    Machine(Machine &&) = delete;
    Machine &operator=(const Machine &) = delete;
    Machine &operator=(Machine &&) = delete;

private:

    // output period in seconds
    unsigned int outputPeriodInSeconds_;

    // data table mapping for frequency count
    std::map<int, int> _dataTableFrequencyMap;

    // actually not first thousand, I am guessing maybe only few correct fibonacci
    // will be supported by unsigned long long. We need a custom big integer class.
    std::set<unsigned long long> firstThousandFiboncciSet_;

    // timer object
    StartStopPauseTimer *startStopPauseTimer_;

    // abstract member
    std::unique_ptr<AbstractState> machineState_;

    //mutex to safeguard critical section.
    // Probably better to have a mutext even though ONLY one thread is writing 
    // the data table.
    std::mutex mutex_;
    
    // private function to call sorting
    void sortAndPrintData();
};