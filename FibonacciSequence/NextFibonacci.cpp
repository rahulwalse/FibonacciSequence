/*
    Implementation for accepting two consecutive Fibonacci numbers and returning next Fibonacci numbers.
*/

int NextFibonacci(int fibonacciTermOne, int fibonacciTermTwo)
{
    int precedingTerm, currentTerm, nextTerm;
    precedingTerm = fibonacciTermOne;
    currentTerm = fibonacciTermTwo;
    nextTerm = precedingTerm + currentTerm;
    return nextTerm;
}