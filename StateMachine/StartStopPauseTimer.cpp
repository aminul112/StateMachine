#include "StartStopPauseTimer.h"

StartStopPauseTimer::StartStopPauseTimer()
{
  // Initialize status when object is created
    isPaused_ = false; 
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
   
    if (isStopped_) {
        startTime_ = time(0);
        isStopped_ = false;
    } else if (isPaused_) {
        isPaused_ = false;
      // Update start time: use the time at this time-the time used during the
      // pause + the last start time = the start time at this time
        startTime_ += time(0) - pauseTime_; 
    }
}

int StartStopPauseTimer::getStartTime()
{
    return startTime_;
}

void StartStopPauseTimer::pause() //time out
{
    // If it is in the stop/pause machineState_, this action will not do any
    // processing and return directly
    if (isStopped_ || isPaused_) 
        return;    
    else 
    {
        // Or pause the timer
        isPaused_ = true;
      // Get the pause time as current time
        pauseTime_ = time(0); 
    }
}
void StartStopPauseTimer::stop() //stop
{
   
    // If it is in a stopped state do not do anything
    if (isStopped_) 
        return;
    
    else if (isPaused_) {
      // Change status to stopped status in case if i is paused
        isPaused_ = false;
        isStopped_ = true;
    } else if (!isStopped_) {
        // if not stopped state, then sto it.
        isStopped_ = true;
    }
}
