#pragma once
#include <iostream>


/**
 * @class StartStopPauseTimer
 *
 * @brief This class dealt with timer.
 *
 */

class StartStopPauseTimer
{
public:
    /**
    * @brief constructor
    *
    */
    StartStopPauseTimer();

    /**
     * @brief returns if the state is paused or not
     *
     */
    bool isPaused();

    /**
     * @brief returns if the state is stopped or not
     *
     */
    bool isStopped();

    /**
     * @brief starts the timer
     *
     */
    void start();

    /**
     * @brief pauses the timer
     *
     */
    void pause();

    /**
     * @brief stops the timer
     *
     */
    void stop();

    /**
     * @brief return the statrt time of this timer
     *
     */
    int getStartTime();

private:
    //start time of timer
    long startTime_;

    // when the timer was paused
    long pauseTime_;

    
    // to mark if the timer is paused or not
    bool isPaused_;  
    
    // to mark if the timer is stopped or not
    bool isStopped_; 

};
