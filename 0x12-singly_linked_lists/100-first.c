#include <stdio.h>

void startup_function(void) __attribute__((constructor));

/**
 * startup_function - Prints start up message before main is executed.
 */

void startup_function(void)
{
	printf("You're beat! and yet, you must allow,\n"
		"I bore my house upon my back!\n");
}
