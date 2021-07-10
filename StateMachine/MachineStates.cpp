// MachineStates.cpp
#include "MachineStates.h"
#include <iostream>

AbstractState::~AbstractState() {}

void AbstractState::setMachineState(Machine &machine, std::unique_ptr<AbstractState> machineState_)
{

    machine.machineState_ = std::move(machineState_);
}



RunState::~RunState() {}

void RunState::getUserInput(Machine &machine)
{
    // We are not catching exception here because make_unique is exception safe.

    char ch;
    std::cin >> ch;
    if (ch == PAUSE) {
        //enter to pause machineState_
        setMachineState(machine, std::make_unique<PauseState>());

        // pause startStopPauseTimer_ first
        machine.pauseTimer();

        machine.getUserInput();
    }
    if (ch == NUMBER) {

        // Note: we are not blocking printing( optional requirement)
        int number;
        std::cout << "Please enter the new number:";
        std::cin >> number;

        machine.isFiboncciNumber(number);
        // add number data table
        machine.addNumberToDataTableFrequencyMap(number);
        machine.getUserInput();
    }
    if (ch == QUIT) {
        machine.stopTimer();
        machine.pauseTimer();
        machine.printDataTableWithGoodByeMessage();
        return;
    }
    if (ch == RUN) {
        // if user presse R inside RUN state, then do nothing
        machine.getUserInput();
    }
}

PauseState::~PauseState() {}

void PauseState::getUserInput(Machine &machine)
{

    // We are not catching exception here because make_unique is exception safe.
    char ch;
    std::cin >> ch;
    if (ch == RUN) {
        //enter to run machineState_
        setMachineState(machine, std::make_unique<RunState>());

        // start startStopPauseTimer_ again
        machine.startTimer();
        machine.getUserInput();
    }
    if (ch == NUMBER) {

        // Note: we are not blocking printing( optional requirement)
        int number;
        std::cout << "Please enter the new number:";
        std::cin >> number;

        machine.isFiboncciNumber(number);
        // add number data to map and sort
        machine.addNumberToDataTableFrequencyMap(number);
        machine.getUserInput();
    }

    if (ch == QUIT) {

        machine.stopTimer();
        machine.pauseTimer();
        //before quiting, print good bye message
        machine.printDataTableWithGoodByeMessage();
        return;
    }
    if (ch == PAUSE) {
        // if user presse P inside PAUSE state, then do nothing
        machine.getUserInput();
    }
}
