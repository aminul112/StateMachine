#include "pch.h"
#include "CppUnitTest.h"
#include "../StateMachine/GenerateFibonacciNumbers.h"
#include "../StateMachine/Machine.h"
#include "../StateMachine/MachineStates.h"
#include "../StateMachine/StartStopPauseTimer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMicrosoft
{
TEST_CLASS(GenerateFibonacciTest)
	{
	public:
		
		TEST_METHOD(CheckfirstNumber)
		{
			
			std::set<int> firstThousandFiboncciSet;
            GenerateFibonacciNumbers::generateFibonacciNumbersSet(
                      firstThousandFiboncciSet, 1);

            Assert::AreEqual(int(firstThousandFiboncciSet.size()), 1);
            Assert::AreEqual(firstThousandFiboncciSet.find(1) ==
                                firstThousandFiboncciSet.end(),
                            true);
                


		}


		TEST_METHOD(CheckThousandNumbers) {
                  std::set<int> firstThousandFiboncciSet;
                  GenerateFibonacciNumbers::generateFibonacciNumbersSet(
                      firstThousandFiboncciSet, 1000);

                  Assert::AreEqual(int(firstThousandFiboncciSet.size()), 1000);
                  
                }
	};

TEST_CLASS(StartStopPauseTimerTest){
          public : 
              TEST_METHOD(CheckInitialStatus){
          
               StartStopPauseTimer timer;
               Assert::AreEqual(timer.isPaused(), false);
               Assert::AreEqual(timer.isStopped(), true);

               int startTime1 = timer.getStartTime();

               timer.start();

               int startTime2 = timer.getStartTime();
        

               Assert::AreNotSame(startTime1, startTime2);         
          
          }
          TEST_METHOD(CheckAfterStop) {
            StartStopPauseTimer timer;
            Assert::AreEqual(timer.isStopped(), true);
            int startTime1 = timer.getStartTime();
            timer.start();
            int startTime2 = timer.getStartTime();
            Assert::AreNotSame(startTime1, startTime2);
            Assert::AreEqual(timer.isStopped(), false);

           }




          TEST_METHOD(CheckAfterPause) {
             StartStopPauseTimer timer2;
             bool x = timer2.isPaused();
             Assert::AreEqual(timer2.isPaused(), false);
             int startTime1 = timer2.getStartTime();
             timer2.start();
             timer2.pause();
             Assert::AreEqual(timer2.isPaused(), true);
          }
        };


}
