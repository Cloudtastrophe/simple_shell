#include "main.h"

/**
 * print_positive_int - Helper function to print a positive integer
 * @n: The positive integer to print
 * @buffer: Buffer to store the printable characters
 * @buffer_index: Current index of the buffer
 * Return: Number of printed characters
 */
static int print_positive_int(unsigned int n, char *buffer, int *buffer_index)
{
    int printed_characters = 0;
    char nums[10];
    int x = 0;

    if (n == 0)
    {
        printed_characters += add_to_buffer(buffer, buffer_index, '0');
        return (printed_characters);
    }

    while (n != 0)
    {
        nums[x] = (n % 10) + '0';
        n /= 10;
        x++;
    }

    while (x >= 1)
    {
        printed_characters += add_to_buffer(buffer, buffer_index, nums[x - 1]);
        x--;
    }

    return (printed_characters);
}

int main(void)
{
    char buffer[100];
    int buffer_index = 0;
    unsigned int number_to_print = 12345;

    /*Call the print_positive_int function*/
    int printed_chars = print_positive_int(number_to_print, buffer, &buffer_index);

    /*Print the result*/
    printf("Printed %d characters: %s\n", printed_chars, buffer);

    return 0;
}
