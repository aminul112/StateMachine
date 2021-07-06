#include <chrono>
#include <iostream>

#include "GenerateFibonacciNumbers.h"
#include "Machine.h"
#include "MachineStates.h"
#include "StartStopPauseTimer.h"
#include "pch.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
  std::set<int> firstThousandFiboncciSet;

  GenerateFibonacciNumbers::generateFibonacciNumbersSet(
      firstThousandFiboncciSet, 1000);
}

TEST(GenerateFibonacciTest, CheckfirstNumber) {
  std::set<int> firstThousandFiboncciSet;

  GenerateFibonacciNumbers::generateFibonacciNumbersSet(
      firstThousandFiboncciSet, 1);

  ASSERT_EQ(firstThousandFiboncciSet.size(), 1);
  ASSERT_EQ(firstThousandFiboncciSet.find(1) == firstThousandFiboncciSet.end(),
            true);
}

TEST(GenerateFibonacciTest, CheckThousandNumbers) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);

  std::set<int> firstThousandFiboncciSet;

  GenerateFibonacciNumbers::generateFibonacciNumbersSet(
      firstThousandFiboncciSet, 1000);

  ASSERT_EQ(firstThousandFiboncciSet.size(), 1000);
}

TEST(StartStopPauseTimerTest, CheckInitialStatus) {
  StartStopPauseTimer timer;
  EXPECT_EQ(timer.isPaused(), false);
  EXPECT_EQ(timer.isStopped(), true);

  int startTime1 = timer.getStartTime();

  timer.start();

  int startTime2 = timer.getStartTime();

  EXPECT_NE(startTime1, startTime2);
  EXPECT_GT(startTime2, startTime1);
}

TEST(StartStopPauseTimerTest, CheckAfterStop) {
  StartStopPauseTimer timer;
  EXPECT_EQ(timer.isStopped(), true);

  int startTime1 = timer.getStartTime();

  timer.start();

  int startTime2 = timer.getStartTime();
  EXPECT_NE(startTime1, startTime2);
  EXPECT_GT(startTime2, startTime1);

  EXPECT_EQ(timer.isStopped(), false);
}

TEST(StartStopPauseTimerTest, CheckAfterPause) {
  StartStopPauseTimer timer;
  EXPECT_EQ(timer.isPaused(), false);

  int startTime1 = timer.getStartTime();

  timer.start();
  timer.pause();

  EXPECT_EQ(timer.isPaused(), true);
}
