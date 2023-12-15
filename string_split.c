#include "main.h"

/**
 * init_arr - Initializes an array of strings based on the given string and delimiters.
 * @trim_str: The string to split.
 * @str_arr: The array of strings to initialize.
 * @arr_size: The size of the array str_arr.
 * @delim: The delimiters to split the string with.
 */
void init_arr(char *trim_str, char **str_arr, int arr_size, char *delim);

/**
 * str_split - Splits a string into an array of words using specified delimiters.
 * @str: The string to split.
 * @delim: The delimiters to split the string with.
 * Return: A pointer to an array of strings (words).
 */
char **str_split(char *str, char *delim)
{
	char **str_arr;
	int arr_size = 1;
	int i, x;
	int str_len = 0;

	/* Count the number of words in the string */
	for (i = 0; str[i] != '\0'; i++)
	{
		if (is_delim(str[i], delim) && !is_delim(str[i + 1], delim))
		{
			arr_size++;
		}
	}

	/* Allocate memory for the array of strings */
	str_arr = malloc(sizeof(char *) * (arr_size + 1));
	if (str_arr == NULL)
	{
		return (NULL);
	}

	/* Initialize the array of strings */
	init_arr(str, str_arr, arr_size, delim);
	return (str_arr);
}

/**
 * init_arr - Initialize the passed array of strings.
 * @str: The string used to initialize the array.
 * @str_arr: The array of strings to initialize with proper data.
 * @arr_size: The size of the array str_arr.
 * @delim: The delimiters to split the string with.
 */
void init_arr(char *str, char **str_arr, int arr_size, char *delim)
{
	int i = 0;
	int x, j;

	/* Loop through each word and initialize the array of strings */
	for (x = 0; x < arr_size; x++)
	{
		j = 0;
		while (str[i] != '\0')
		{
			if (is_delim(str[i], delim))
			{
				i++;
				break;
			}
			str_arr[x][j] = str[i];
			j++;
			i++;
		}
		str_arr[x][j] = '\0';
	}

	/* Set the last element of the array to NULL to indicate the end */
	str_arr[x] = NULL;
}

/**
 * is_delim - Checks if a character is a delimiter.
 * @c: The character to check.
 * @delimiters: The delimiters to compare with.
 * Return: 1 if the character is a delimiter, or 0 otherwise.
 */
int is_delim(char c, char *delimiters)
{
	int i;

	/* Iterate through delimiters and check if the character is one of them */
	for (i = 0; delimiters[i] != '\0'; i++)
	{
		if (c == delimiters[i])
			return 1;
	}
	return 0;
}
