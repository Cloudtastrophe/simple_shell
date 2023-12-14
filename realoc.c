#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size, in bytes, of the allocated space for ptr.
 * @new_size: The new size, in bytes, of the new memory block.
 * Return: A pointer to the new allocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *result;
	unsigned int i = 0;

	if (old_size == new_size)
	{
		/* If the old and new sizes are the same, no need to reallocate. */
		return (ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		/* If new size is 0 and ptr is not NULL, free the memory and return NULL. */
		free(ptr);
		return (NULL);
	}

	result = malloc(new_size);

	if (result == NULL)
	{
		/* Return NULL if malloc fails to allocate memory. */
		return (NULL);
	}

	if (ptr == NULL)
	{
		/* If ptr is NULL, return the newly allocated memory. */
		return (result);
	}

	while (i < old_size && i < new_size)
	{
		/* Copy the content from the old memory block to the new one. */
		result[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (result);
}
