#include <stdio.h>

int main(int argc, char *argv[])
{
if (argc != 2)
{
printf("Usage: %s <password>\n", argv[0])
return (1);
}
if (strcmp(argv[1], "Your_Valid_Password") == 0)
{
printf("Tada! Congrats\n");
}
else
{
printf("Try again\n");
}
return (0);
}
