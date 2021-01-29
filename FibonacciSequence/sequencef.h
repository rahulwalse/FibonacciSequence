/*
	This header file contains declarations for all the functions used for 
	calculating and generating sequences like Fibonacci sequence, Lucas 
	sequence.
*/

#ifndef SEQUENCEF_H
#define SEQUENCEF_H

int Fibonacci(int number);
int NextFibonacci(int fibonacciTermOne, int fiboancciTermTwo);
int LucasSequence(int number);
int ThreeNumberSequence(int number);
void DetermineFibonacci(int numberOne, int numberTwo);

#endif /* !SEQUENCEF_H*/