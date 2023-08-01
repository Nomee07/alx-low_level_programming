#include "main.h"
#include <stdio.h>

/**
 * set_string - Sets the value of a pointer to a char.
 * @s: The double pointer to be updated with the new value.
 * @to: The new value to be set.
 */

void set_string(char **s, char *to)
{
	*s = to;
}
