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

// to avoid including Machine.h
class Machine;

/**
 * @class AbstractState
 *
 * @brief The abstract base class for state. Other child clases will implement all
 * functions of this class  to define a state.
 *
 */
class AbstractState
{
public:
  /**
   * @brief pure virtual function to get user input
   * @param machine macine objec
   *
   */
    virtual void getUserInput(Machine &machine) = 0;

    // destructor
    virtual ~AbstractState();

protected:
    /**
     * @brief to set a state of a state machine.
     *
     * @param machine macine objec
     * @param a pointer to a child state
     */  
    void setMachineState(Machine &machine, std::unique_ptr<AbstractState> st);
    
};


/**
 * @class RunState
 *
 * @brief The RunState class to deal with what happens in the run state.
 *
 */

class RunState : public AbstractState
{
public:
    virtual void getUserInput(Machine &machine);

    // destructor
    virtual ~RunState();
};


/**
 * @class PauseState
 *
 * @brief The PauseState class to deal with what happens in the Pause state.
 *
 */


class PauseState : public AbstractState
{
public:
    virtual void getUserInput(Machine &machine);

    // destructor
    virtual ~PauseState();
};
