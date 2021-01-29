/*
    Implementation for generating sequence by adding the recent three numbers.
*/

#include <iostream>
#include "sequencef.h"
using namespace std;

int ThreeNumberSequence(int number)
{
    int precedingTerm = 0, middleTerm = 1, nextTerm = 1, newTerm;

    /*
        Generate sequence by adding recent three numbers (initially 0, 1, 1)
        and then interchanging values of previous three terms to the recent three terms.
    */
    cout << "\nThe sequence is: " << endl;
    for (int iteration = 0; iteration < number; iteration++)
    {
        cout << " " << precedingTerm;
        /*Use the function NextFibonacciNumber and add to 'next_term'.*/
        newTerm = NextFibonacci(precedingTerm, middleTerm) + nextTerm;
        /*Change the values of all three terms so that they store most recent three values accordingly.*/
        precedingTerm = middleTerm;
        middleTerm = nextTerm;
        nextTerm = newTerm;
    }
    return 0;
}