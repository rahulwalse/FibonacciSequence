/*
    Implementation for generating Fibonacci sequence with total terms >= 1.
*/

#include <iostream>
using namespace std;

int Fibonacci(int number)
{
    int PrecedingTerm = 0, CurrentTerm = 1, NewTerm;
    /*
        Generate the Fibonacci sequence by adding previous two numbers (initially
        0 & 1) and then interchanging values of previous two terms to the recent 
        two terms.
    */
    cout << "\nThe Fibonacci sequence for " << number << " terms is: ";
    for (int iteration = 0; iteration < number; iteration++)
    {
        cout << " " << PrecedingTerm;
        NewTerm = PrecedingTerm + CurrentTerm;
        PrecedingTerm = CurrentTerm;
        CurrentTerm = NewTerm;
    }
    return 0;
}