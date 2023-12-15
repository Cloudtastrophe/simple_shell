#include "main.h"

/**
 * print_int_format - Prints the integer argument in the format
 *                    used by the print_error function.
 * @ptr: The pointer to the list of arguments of the print_error function.
 * @buffer: The buffer to store the printable characters.
 * @buffer_index: The current index of the buffer.
 * Return: The number of printed characters.
 */
int print_int_format(va_list ptr, char *buffer, int *buffer_index)
{
	int num = va_arg(ptr, int);  /*Get the integer argument from the va_list*/
	int digit, printed_characters = 0;
	unsigned int absolute_value;

	char digits_buffer[10];  /*Buffer to store individual digits of the number*/

	if (num == 0)
	{
		/* Special case: If the number is zero, print '0' and return*/
		printed_characters += add_to_buffer(buffer, buffer_index, '0');
		return printed_characters;
	}

	/*Handle negative numbers*/
	if (num < 0)
	{
		printed_characters += add_to_buffer(buffer, buffer_index, '-');
		absolute_value = (unsigned int)(-num);
	}
	else
	{
		absolute_value = (unsigned int)num;
	}

	/*Extract individual digits of the absolute value*/
	int digit_index = 0;
	while (absolute_value != 0)
	{
		digit = absolute_value % 10;
		digits_buffer[digit_index] = digit + '0';
		absolute_value /= 10;
		digit_index++;
	}

	/* Print the digits in reverse order*/
	while (digit_index >= 1)
	{
		printed_characters += add_to_buffer(buffer, buffer_index, digits_buffer[digit_index - 1]);
		digit_index--;
	}

	return printed_characters;
}
