// MachineStates.h
#pragma once

#include "Machine.h"
#include <exception>
#include <stdexcept>
#include <memory>

const char PAUSE = 'P';
const char RUN = 'R';
const char NUMBER = 'N';
const char QUIT = 'Q';

class Machine;

class AbstractState
{
public:
    virtual void getUserInput(Machine &machine) = 0;
    virtual ~AbstractState();

protected:
    void setMachineState(Machine &machine, std::unique_ptr<AbstractState> st);
    
};

class RunState : public AbstractState
{
public:
    virtual void getUserInput(Machine &machine);
    virtual ~RunState();
};

class PauseState : public AbstractState
{
public:
    virtual void getUserInput(Machine &machine);
    virtual ~PauseState();
};
