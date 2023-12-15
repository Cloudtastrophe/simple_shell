#include "main.h"

/**
 * main - Entry point of the program
 *
 * Description: This function writes "Hello, Betty!" to the standard output.
 * Return: Always 0 (Success)
 */
int main(void)
{
    char betty[] = "Hello, Betty!\n";
    int i;

    for (i = 0; betty[i] != '\0'; i++)
    {
        write(1, &betty[i], 1);
    }

    return (0);
}
