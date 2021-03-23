/*
	Implementation for generating sequence, where each member is the sum of adjacent factorials, i.e,
	f3 = 1! + 0!
	f4 = 2! + 1!
	f5 = 3! + 2!
*/

#include <iostream>
#include "sequencef.h"
using namespace std;

void AdjacentFactorialSum(int number)
{
	int precedingTerm = 0, currentTerm = 1, newTerm;	long long adjacentFactorialSum;
	cout << "Generating sequence, where each member is the sum of adjacent factorial, i.e, f3 = 1! + 0!,";
	cout << "f4 = 2!+ 1!, f5 = 3!+ 2! and so on." << endl;
	cout << "\nThe sequence of sum of adjacent factorials of order " << number << " is:" << endl;
	/*Display the first term in the sequence if the total term is 1.*/
	if (number == 1)
	{
		cout << Factorial(precedingTerm) << " " << endl;	/*Calculate the factorial of first term.*/
	}
	else
	{
		/*Generate and display the first two terms by calculating the factorials.*/
		cout << Factorial(precedingTerm) << " " << Factorial(currentTerm) << " ";
		/*
			For the third term and beyond calculate the factorial of adjacent terms and the add the result
			to get the new term.
		*/
		for (int iteration = 2; iteration < number; iteration++)
		{
			adjacentFactorialSum = Factorial(currentTerm) + Factorial(precedingTerm);
			cout << adjacentFactorialSum << " ";
			currentTerm++;
			precedingTerm++;
		}
	}
}