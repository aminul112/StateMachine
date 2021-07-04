#include "GenerateFibonacciNumbers.h"

void GenerateFibonacciNumbers::generateFibonacciNumbersSet(std::set<int> &firstThousandFiboncciSet_, int total)
{

    int fib1 = 0;
    int fib2 = 1;
    int fib3 = 0;
    if (total == 1) {
        firstThousandFiboncciSet_.insert(0);
        return;
    }

    if (total == 2) {
        firstThousandFiboncciSet_.insert(0);
        firstThousandFiboncciSet_.insert(1);
        return;
    }
    total = total + 2;

    for (int i = 2; i < total; i++) {
        fib3 = fib1 + fib2;
        firstThousandFiboncciSet_.insert(fib3);
        fib1 = fib2;
        fib2 = fib3;
    }
}
