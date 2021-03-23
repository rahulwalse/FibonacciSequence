/*FibonacciSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.*/
/*
    This program is an implementation in C++ of algorithm for generating Fibonacci sequence including supplementary
    problems and algorithms for sequence computations from the book "How to Solve it by Computer" by R.G. Dromey.
*/

#include <iostream>
#include "sequencef.h"
using namespace std;
const int FIRSTOPTION = 1, LASTOPTION = 6;



int main()
{
    int choice, terms, number, numberOne, numberTwo;
    char cont;
    do
    {


        cout << "\n1. Generate Fibonacci sequence\n2. Generate next Fibonacci number by accepting two consecutive Fibonacci numbers";
        cout << "\n3. Generate Lucas sequence (1 3 4 7 11...)\n4. Generate a sequence by adding recent three numbers, where initial terms are 0 1 1";
        cout << "\n5. Check if the given two numbers are Fibonacci numbers\n6. Generate sequence where each term is sum of adjacent factorials\nEnter your choice: ";
        cin >> choice;

        if (choice < FIRSTOPTION || choice > LASTOPTION)    /*Check if the choice entered by the user is valid.*/
        {
            cout << "\nThe option selected is not provided, exiting the program..." << endl;
            return 0;
        }
        else
        {
            switch (choice)
            {
            case 1: cout << "\nEnter the number of terms in the Fibonacci sequence" << endl;
                    cout << "terms=";   cin >> terms;
                    if (terms < 1)
                    {
                        cout << "\nFibonacci sequence cannot be generated for " << terms << " terms." << endl;
                        return 0;
                    }
                    else
                    {
                        Fibonacci(terms);
                    }
                    break;

            case 2: cout << "\nEnter two consecutive Fibonacci numbers" << endl;
                    cout << "Fibonacci number one=";    cin >> numberOne;
                    cout << "Fibonacci number two=";    cin >> numberTwo;
                    cout << "\nThe next Fibonacci number is: " << NextFibonacci(numberOne, numberTwo);
                    break;

            case 3: cout << "\nEnter the number of terms in the Lucas sequence" << endl;
                    cout << "terms=";   cin >> terms;
                    if (terms < 1)
                    {
                        cout << "\nLucas sequence cannot be generated for " << terms << " terms." << endl;
                        return 0;
                    }
                    else
                    {
                        LucasSequence(terms);
                    }
                    break;

            case 4: cout << "\nEnter the total number of terms to generate" << endl;
                    cout << "Terms=";   cin >> terms;
                    if (terms < 1)
                    {
                        cout << "\nThe sequence cannot be generated for " << terms << " terms." << endl;
                        return 0;
                    }
                    else
                    {
                        ThreeNumberSequence(terms);
                    }
                    break;

            case 5: cout << "\nEnter the two numbers to determine whether they are Fibonacci numbers\nNote: This still is a work in progress." << endl;
                    cout << "first number=";    cin >> numberOne;
                    cout << "second number=";   cin >> numberTwo;
                    DetermineFibonacci(numberOne, numberTwo);
                    break;

            case 6: cout << "\nEnter the total number of terms in the sequence to be generated" << endl;
                    cin >> terms;
                    if (terms < 1)
                    {
                        cout << "\nThe sequence cannot be generated for " << terms << " terms." << endl;
                        return 0;
                    }
                    else
                    {
                        AdjacentFactorialSum(terms);
                    }
                    break;
            }
        }
        /*Check if the user wants to continue.*/
        cout << "\nDo you want to continue? (Y/N)" << endl;
        cin >> cont;
    } while (cont == 'Y' || cont == 'y');
}