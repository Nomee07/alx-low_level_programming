#include <stdio.h>

/**
 * main - The program prints all arguments it receives
 * @argc: The number of arguments
 * @argv: Arrays of arguments
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
