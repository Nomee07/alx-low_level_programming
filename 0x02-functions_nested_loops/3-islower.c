#include "main.h"
/**
 *_islower - checks if char is lowercase
 *@c: the character to be checked
 *Return: 1 if c is a letter, 0 character
 */
int _islower(int c)
{
if (c >= 97 && c <= 122)
{return (1);
}
return (0);
}
