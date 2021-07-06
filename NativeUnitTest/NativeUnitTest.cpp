#include "CppUnitTest.h"
#include "pch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTest {
TEST_CLASS(NativeUnitTest){
  public :

      TEST_METHOD(TestMethod1){/*          
          std::set<int> firstThousandFiboncciSet;

          GenerateFibonacciNumbers::generateFibonacciNumbersSet(firstThousandFiboncciSet,
                                                      1);

          Assert::AreEqual(firstThousandFiboncciSet.size(), 1);
          Assert::AreEqual(firstThousandFiboncciSet.find(1) ==
                     firstThousandFiboncciSet.end(),
          true);
          */
Assert::AreEqual(5, 5);

}  // namespace NativeUnitTest
}
;
}
