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
}
