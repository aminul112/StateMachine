#pragma once
#include <iostream>




class StartStopPauseTimer
{
private:
    long startTime_;
    long pauseTime_;
    //Two bool values ​​mark four states
    bool isPaused_; //Record the status of the StartStopPauseTimer (whether it is in a paused machineState_)
    bool isStopped_;  //Is it in a stopped machineState_?
public:
    StartStopPauseTimer();
    bool isPaused();
    bool isStopped();
    //Three actions (functions) of the startStopPauseTimer_
    void start();
    void pause();
    void stop();
    int getStartTime();
};
