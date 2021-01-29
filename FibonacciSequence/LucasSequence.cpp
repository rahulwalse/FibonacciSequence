/*
    Implementation for generating Lucas sequence (1 3 4 7 11...) for total terms greater than 
    equal to 1.
*/

#include <iostream>
#include "sequencef.h"
using namespace std;

int LucasSequence(int number)
{
    int precedingTerm = 1, currentTerm = 3, newTerm;

    cout << "\nThe Lucas sequence for " << number << " terms is: " << endl;
    /*
        Generate the Lucas sequence by adding previous two numbers (initially 1 & 3)
        and then interchanging values of previous two terms to the recent two terms.
    */
    for (int iteration = 0; iteration < number; iteration++)
    {
        cout << " " << precedingTerm;
        newTerm = NextFibonacci(precedingTerm, currentTerm);
        precedingTerm = currentTerm;
        currentTerm = newTerm;
    }
    return 0;
}