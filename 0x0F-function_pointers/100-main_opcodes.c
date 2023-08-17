#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - Printsopcodes of a function.
 * @start: Starting address of the function.
 * @size: Number of bytes to print.
 */

void print_opcodes(unsigned char *start, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("%02x", start[i]);

		if (i < size - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * main - Entry point of the program.
 * @argc: Number of command line arguments.
 * @argv: Array of command line argument strings.
 *
 * Return: 0 if successful or 1 if invalid.
 */

int main(int argc, char *argv[])
{
	int num_bytes = atoi(argv[1]);
	unsigned char *main_addr = (unsigned char *)main;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}
	print_opcodes(main_addr, (size_t)num_bytes);
	return (0);
}
