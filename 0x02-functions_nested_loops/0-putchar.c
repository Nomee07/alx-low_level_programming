#include <stdio.h>
/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
char text[] = "_putchar";
int i = 0;
while (text[i] != '\0')
{
char ch = text[i];
putchar(ch);
i++;
}
putchar('\n');
return (0);
}
