// FibonacciSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
    This program generates Fibonacci sequence and other sequences.
*/

#include <iostream>
using namespace std;
const int FirstOption = 1, LastOption = 5;

int FibonacciSequence(int number);
int NextFibonacciNumber(int fibonacci_one, int fiboancci_two);
int LucasSequence(int number);
int ThreeNumberSequence(int number);
void DetermineFibonacciNumbers(int numberone, int numbertwo);
int JustFibonacci(int number);

int main()
{
    int choice, total_terms, number, number1, number2;
    cout << "\n1. Generate Fibonacci sequence\n2. Generate next Fibonacci number by accepting two consecutive Fibonacci numbers";
    cout << "\n3. Generate Lucas sequence (1 3 4 7 11...)\n4. Generate a sequence by adding recent three numbers, where initial terms are 0 1 1";
    cout << "\n5. Check if the given two numbers are Fibonacci numbers\nEnter your choice: ";
    cin >> choice;

    if (choice < FirstOption or choice > LastOption)    //Check if the choice entered by the user is valid.
    {
        cout << "\nThe choice you entered is not from the options provided, exiting the program..." << endl;
        return 0;
    }
    else
    {
        switch (choice)
        {
        case 1: cout << "\nEnter the number of terms in the Fibonacci sequence" << endl;
            cout << "terms=";   cin >> total_terms;
            if (total_terms < 1)
            {
                cout << "\nFibonacci sequence cannot be generated for " << total_terms << " terms." << endl;
                return 0;
            }
            else
            {
                FibonacciSequence(total_terms);
            }
            break;

        case 2: cout << "\nEnter two consecutive numbers" << endl;
            cout << "Fibonacci number one:";    cin >> number1;
            cout << "Fibonacci number two:";    cin >> number2;
            cout << "\nThe next Fibonacci number is: " << NextFibonacciNumber(number1, number2);
            break;

        case 3: cout << "\nEnter the number of terms in the Lucas sequence" << endl;
            cout << "terms=";   cin >> total_terms;
            if (total_terms < 1)
            {
                cout << "\nLucas sequence cannot be generated for " << total_terms << " terms." << endl;
                return 0;
            }
            else
            {
                LucasSequence(total_terms);
            }
            break;

        case 4: cout << "\nEnter the total number of terms to generate" << endl;
            cout << "Terms=";   cin >> total_terms;
            if (total_terms < 1)
            {
                cout << "\nThe sequence cannot be generated for " << total_terms << " terms." << endl;
                return 0;
            }
            else
            {
                ThreeNumberSequence(total_terms);
            }
            break;

        case 5: cout << "\nEnter the two numbers to determine whether they are Fibonacci numbers\nNote: This still is a work in progress." << endl;
            cout << "first number=";    cin >> number1;
            cout << "second number=";   cin >> number2;
            DetermineFibonacciNumbers(number1, number2);
            break;
        }
    }
}

//Implementation for generating Fibonacci sequence with total terms >= 1.
int FibonacciSequence(int number)
{
    int preceding_term = 0, current_term = 1, new_term;

    if (number == 1)  //When the total terms in sequence is 1, display the first number (preceding_term).
    {
        cout << "\nThe Fibonacci sequence is for term = " << number << " is: " << preceding_term;
    }
    else
    {
        /*
            Here it will display the numbers in Fibonacci sequence, when the total terms is 2 (or more), the following statement will display the first
            two terms. Where the total terms (number) are more than 2 the for loop will generate the terms until iteration is less than the number.
        */
        cout << "\nThe Fibonacci sequence is for term = " << number << " is: " << preceding_term << " " << current_term;

        for (int iteration = 2; iteration < number; iteration++)    //The iteration begins from 2, as the first two terms are by definition.
        {
            new_term = preceding_term + current_term;
            preceding_term = current_term;
            current_term = new_term;
            cout << " " << new_term;
        }
    }
    return 0;
}

//Implementation for accepting two consecutive Fibonacci numbers and returning next Fibonacci numbers.
int NextFibonacciNumber(int fibonacci_one, int fibonacci_two)
{
    return fibonacci_one + fibonacci_two;
}

//Implementation for generating Lucas sequence (1 3 4 7 11...) for total terms >= 1.
int LucasSequence(int number)
{
    int preceding_term = 1, current_term = 3, new_term;

    if (number == 1)    //When the total term is 1, display the first term (preceding_term).
    {
        cout << "\nThe Lucas sequence for term = " << number << " is: " << preceding_term << endl;
    }
    else
    {
        /*
            When the total term is 2, the following statement will display first two terms. When the total terms are more than 2,
            the following statement will display first two terms and the rest of the terms will be generated and displayed by the
            for loop.
        */
        cout << "\nThe Lucas sequence for term = " << number << " is: " << preceding_term << " " << current_term;

        for (int iteration = 2; iteration < number; iteration++)    //The for loop will generate terms after the first two terms in sequence.
        {
            new_term = NextFibonacciNumber(preceding_term, current_term);
            preceding_term = current_term;
            current_term = new_term;
            cout << " " << new_term;
        }
    }
    return 0;
}

//Implementation for generating sequence by adding the recent three numbers.
int ThreeNumberSequence(int number)
{
    int preceding_term = 0, middle_term = 1, next_term = 1, new_term;

    if (number == 1)  //When the total term is 1, display the first term (value of 'preceding_term').
    {
        cout << "\nThe sequence is: " << preceding_term;
    }
    else if (number == 2) //When the total terms are 2, display the first two terms (values of 'preceding_term' and 'middle_term').
    {
        cout << "\nThe sequence is: " << preceding_term << " " << middle_term;
    }
    else
    {
        /*
            If the total terms in sequence are 3, then display the values of 'preceding_term', 'middle_term' and 'next_term' for the first three
            terms. And if the total terms in the sequence are more than 3, the following statement will display the first three terms and the
            next term will be generated by the for loop, till the iteration is less than the total terms ('number').
        */
        cout << "\nThe sequence is: " << preceding_term << " " << middle_term << " " << next_term;

        for (int iteration = 3; iteration < number; iteration++)
        {
            new_term = NextFibonacciNumber(preceding_term, middle_term) + next_term;    //Use the function NextFibonacciNumber and add to 'next_term'.
            preceding_term = middle_term;   //Change the values of all three terms so that they store most recent three values accordingly.
            middle_term = next_term;
            next_term = new_term;
            cout << " " << new_term;
        }
    }
    return 0;
}

//Impementation for determining the given two numbers are Fibonacci numbers.
void DetermineFibonacciNumbers(int numberone, int numbertwo)
{
    int first_num, second_num, fibonacci = 0, iteration = 1, flag = 0;
    //Making sure that the lowest number is always the first number.
    if (numberone < numbertwo)
    {
        first_num = numberone;
        second_num = numbertwo;
    }
    else
    {
        first_num = numbertwo;
        second_num = numberone;
    }
    
    while (flag != 1)   //Using flag to terminate the while loop.
    {
        /*
            If the value of Fibonacci for iteration is less than the first number, check the values of
            Fibonacci number for current iteration and Fibonacci value for next iteration are equal to
            first number and second number respectively, then the given numbers are consecutive Fibonacci
            numbers. If not then increment the value of iteration by 1 until it is less than equal to first
            number, if not then the numbers are not Fibonacci numbers.
        */
        if (JustFibonacci(iteration) <= first_num)
        {
            //Check if the values of Fibonacci for current and next values of iteration are equal to first and second number, respectively.
            if (first_num == JustFibonacci(iteration) && second_num == JustFibonacci(iteration + 1))
            {
                cout << "\nThe numbers " << numberone << " & " << numbertwo << " are consecutive Fibonacci numbers." << endl;
                flag = 1;   //Setting value of flag to 1, so as to terminate the while loop.
            }
            else
            {
                //As the numbers are not equal to the current value of Fibonacci of iteration, we need to increment it.
                iteration++;
            }
        }
        else
        {
            cout << "\nThe numbers " << numberone << " & " << numbertwo << " are not the Fibonacci numbers." << endl;
            flag = 1;   //Setting value of flag to 1, so as to terminate the while loop.
        }
    }
}

//Implementation for returning the value of the latest term in the Fibonacci sequence.
int JustFibonacci(int number)
{
    int preceding_term = 0, current_term = 1, next_term = 0;

    if (number == 1)      //When the term is equal to 1, return the value of preceding_term.
    {
        return preceding_term;
    }
    else if (number == 2) //When the term is equal to 2, return the value of current_term.
    {
        return current_term;
    }
    else                //When the terms are more than 2, generate the terms using for loop until the count is less than number.
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