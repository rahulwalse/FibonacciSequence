/*
	Implementation to calculate the factorial of a number.
*/

#include <iostream>

long long Factorial(int number)
{
	long long factorial = 1;	/*Initialize factorial to 1.*/
	/*Set the count to number and decrement for each iteration, multiply it to factorial.*/
	for (int count = number; count >= 1; count--)
	{
		factorial = factorial * count;
	}
	return factorial;
}