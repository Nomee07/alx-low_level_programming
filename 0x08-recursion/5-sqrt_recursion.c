#include "main.h"
#include <stdio.h>

/**
 * _sqrt_helper - A helper function to calculate the square root recursively
 * @n: The number for which the square root is to be computed
 * @guess: The current guess for the square root
 *
 * Return: The square root of n
 */
int _sqrt_helper(int n, int guess)
{
	int square = guess * guess;

	if (square == n)
		return (guess);
	else if (square > n)
		return (-1);

	return (_sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - Calculates the natural square root of a number
 * @n: The number for which the square root is to be computed
 *
 * Return: The square root of n
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (_sqrt_helper(n, 0));
}
