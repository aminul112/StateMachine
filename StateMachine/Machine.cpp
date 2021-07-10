// machine.cpp
#include "Machine.h"
#include "MachineStates.h"
#include <iostream>
#include <map>
#include <set>

// this is to sort by fequency
struct SortByFrequency
{
    template <typename T>
    bool operator()(const T &l, const T &r) const
    {
        if (l.second != r.second) {
            return l.second > r.second;
        }

        return l.first < r.first;
    }
};

Machine::Machine(unsigned int _output_period_in_seconds,
                 std::map<int, int> &_my_map, StartStopPauseTimer *_timer,
                 std::set<unsigned long long> &_fiboncci_set) {

    // get all dependencies
    outputPeriodInSeconds_ = _output_period_in_seconds;
    _dataTableFrequencyMap = _my_map;
    startStopPauseTimer_ = _timer;
    firstThousandFiboncciSet_ = _fiboncci_set;

    // At first the machine will enter in the Run State. It is alway fixed according to requirement
    machineState_ = static_cast<std::unique_ptr<AbstractState>>(std::make_unique<RunState>());
    startStopPauseTimer_->start();
}

Machine::~Machine()
{
}

// get user input according to the state of the machine.
void Machine::getUserInput() { machineState_->getUserInput(*this); }


void Machine::printDataTable()
{

    while (1) {
        if ((time(0) - startStopPauseTimer_->getStartTime() == outputPeriodInSeconds_) && startStopPauseTimer_->isPaused() == false && startStopPauseTimer_->isStopped() == false) {           
            sortAndPrintData();
            //when we print a data table, timer shall be reset
            startStopPauseTimer_->stop();
            startStopPauseTimer_->start();
        }
    }
}

void Machine::sortAndPrintData()
{
    {        
        std::lock_guard<std::mutex> lockGuard(mutex_);
        std::set<std::pair<int, int>, SortByFrequency> set(_dataTableFrequencyMap.begin(), _dataTableFrequencyMap.end());

        int num_printed = 0;
        for (auto const &pair : set) {
            std::cout << pair.first << ":" << pair.second;
            num_printed++;

            if (num_printed != set.size())
                std::cout << ",";
            else
                std::cout << std::endl;
        }
    }
}

void Machine::printDataTableWithGoodByeMessage()
{
    sortAndPrintData();
    std::cout << "See you next time!";
}

void Machine::stopTimer()
{
    startStopPauseTimer_->stop();
}
void Machine::pauseTimer()
{
    startStopPauseTimer_->pause();
}
void Machine::startTimer()
{
    startStopPauseTimer_->start();
}

void Machine::isFiboncciNumber(unsigned long long _fib_check) {

    if (firstThousandFiboncciSet_.count(_fib_check)) {
        std::cout << "FIB!" << std::endl;
    }
}

void Machine::addNumberToDataTableFrequencyMap(int number)
{   
    {

        std::lock_guard<std::mutex> lockGuard(mutex_);

        if (_dataTableFrequencyMap.find(number) != _dataTableFrequencyMap.end()) {
            _dataTableFrequencyMap[number]++;
        } else {
            _dataTableFrequencyMap[number] = 1;
        }
    }
}