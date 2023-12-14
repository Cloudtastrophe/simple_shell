#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char betty[] = "Hello, Betty!\n";
    int i;

    for (i = 0; betty[i] != '\0'; i++)
    {
        putchar(betty[i]);
    }

    return (0);
}
