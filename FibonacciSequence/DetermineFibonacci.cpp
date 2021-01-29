/*
    Implementation for determining the given two numbers are Fibonacci numbers.
*/

#include <iostream>
#define FOUND 1
#define NOTFOUND 2
using namespace std;

int JustFibonacci(int number);

void DetermineFibonacci(int numberOne, int numberTwo)
{
    int firstNumber, secondNumber, fibonacci = 0, iteration = 1, status = 0;
    /*Making sure that the lowest number is always the first number.*/
    if (numberOne < numberTwo)
    {
        firstNumber = numberOne;
        secondNumber = numberTwo;
    }
    else
    {
        firstNumber = numberTwo;
        secondNumber = numberOne;
    }

    while (status != FOUND && status != NOTFOUND)   /*Using status to terminate the while loop.*/
    {
        /*
            If the value of Fibonacci for iteration is less than the first number, check the values of
            Fibonacci number for current iteration and Fibonacci value for next iteration are equal to
            first number and second number respectively, then the given numbers are consecutive Fibonacci
            numbers. If not then increment the value of iteration by 1 until it is less than equal to first
            number, if not then the numbers are not Fibonacci numbers.
        */
        if (JustFibonacci(iteration) <= firstNumber)
        {
            /*Check if the values of Fibonacci for current and next values of iteration are equal to first and second number, respectively.*/
            if (firstNumber == JustFibonacci(iteration) && secondNumber == JustFibonacci(iteration + 1))
            {
                cout << "\nThe numbers " << numberOne << " & " << numberTwo << " are consecutive Fibonacci numbers." << endl;
                status = FOUND;   /*Setting status to FOUND, so as to terminate the while loop.*/
            }
            else
            {
                /*As the numbers are not equal to the current value of Fibonacci of iteration, we need to increment it.*/
                iteration++;
            }
        }
        else
        {
            cout << "\nThe numbers " << numberOne << " & " << numberTwo << " are not the Fibonacci numbers." << endl;
            status = NOTFOUND;   /*Setting status to NOTFOUND, so as to terminate the while loop.*/
        }
    }
}

/*Implementation for returning the value of the latest term in the Fibonacci sequence.*/
int JustFibonacci(int number)
{
    int preceding_term = 0, current_term = 1, next_term = 0;

    if (number == 1)      /*When the term is equal to 1, return the value of preceding_term.*/
    {
        return preceding_term;
    }
    else if (number == 2) /*When the term is equal to 2, return the value of current_term.*/
    {
        return current_term;
    }
    else                /*When the terms are more than 2, generate the terms using for loop until the count is less than number.*/
    {
        for (int count = 2; count < number; count++)
        {
            next_term = preceding_term + current_term;
            preceding_term = current_term;
            current_term = next_term;
        }
        return next_term;
    }
}