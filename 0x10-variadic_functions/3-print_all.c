#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints values based on provided functions.
 * @format: A format string showing the types of arguments.
 *	c: char
 *	i: integer
 *	f: float
 *	s: char *
 * @...: Additional arguments.
 */

void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	int num;
	float f_num;

	va_start(args, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
			printf("%c", va_arg(args, int));
			break;
			case 'i':
			num = va_arg(args, int);
			printf("%d", num);
			break;
			case 'f':
			f_num = va_arg(args, double);
			printf("%f", f_num);
			break;
			case 's':
			str = va_arg(args, char *);
			if (!str)
				str = "(nil)";
			printf("%s", str);
			break;
			default:
			break;
		}

		if (format[i + 1] != '\0' && (format[i] == 'c' ||
		format[i] == 'i' || format[i] == 'f' || format[i] == 's'))
			printf(", ");
		i++;
	}
	va_end(args);
	printf("\n");
}
