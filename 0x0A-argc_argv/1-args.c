#include <stdio.h>

/**
 * main - Entry point of the program
 * @argc: The number of arguments
 * @argv: Arrays of pointers to the arguments
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	(void)argv; /* ignore argv */
	printf("%d\n", argc - 1);
	return (0);
}
