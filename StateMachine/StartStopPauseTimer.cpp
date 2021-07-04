#include "StartStopPauseTimer.h"

StartStopPauseTimer::StartStopPauseTimer()
{
    isPaused_ = false; //Initialize startStopPauseTimer_ status
    isStopped_ = true;
    pauseTime_ = 0;
    startTime_ = 0;
}

bool StartStopPauseTimer::isPaused()
{
    if (isPaused_)
        return true;
    else
        return false;
}

bool StartStopPauseTimer::isStopped()
{
    if (isStopped_)
        return true;
    return false;
}

void StartStopPauseTimer::start() //Start
{
    //cout << "StartStopPauseTimer started" << endl;
    if (isStopped_) {
        startTime_ = time(0);
        isStopped_ = false;
    } else if (isPaused_) {
        isPaused_ = false;
        startTime_ += time(0) - pauseTime_; //Update start time: use the time at this time-the time used during the pause + the last start time = the start time at this time
    }
}

int StartStopPauseTimer::getStartTime()
{
    return startTime_;
}

void StartStopPauseTimer::pause() //time out
{
    //cout << "StartStopPauseTimer paused" << endl;
    if (isStopped_ || isPaused_) //If it is in the stop/pause machineState_, this action will not do any processing and return directly
        return;
    else //Otherwise, the modulation is suspended
    {
        isPaused_ = true;
        pauseTime_ = time(0); //Get the pause time
    }
}
void StartStopPauseTimer::stop() //stop
{
    //cout << "StartStopPauseTimer stopped" << endl;
    if (isStopped_) //If it is in a stopped machineState_ (not a suspended machineState_), do not do anything
        return;
    else if (isPaused_) //Change startStopPauseTimer_ status
    {
        isPaused_ = false;
        isStopped_ = true;
    } else if (!isStopped_) {
        isStopped_ = true;
    }
}
