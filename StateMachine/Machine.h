// machine.h
#pragma once

#include "MachineStates.h"
#include "StartStopPauseTimer.h"
#include <map>
#include <set>
#include <mutex>

class AbstractState;

class Machine
{
    friend class AbstractState;

public:
    
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

private:
    unsigned int outputPeriodInSeconds_;
    std::map<int, int> dataTableFrequencyMap_;
    std::set<int> firstThousandFiboncciSet_;
    StartStopPauseTimer *startStopPauseTimer_;
    std::unique_ptr<AbstractState> machineState_;
    std::mutex mutex_;
    

    void sortAndPrintData();
};