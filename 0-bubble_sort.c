#include "sort.h"

/**
 * bubble_sort - sorts the given data in ascending order
 * @array: array containing data
 * @size: size of the array
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, len;
	int tmp;

	len = size;
	if (!array)
		return;
	for (; j < size; len--, j++)
	{
		for (i = 0; i < len - 1; i++)
		{
			if (array[i + 1] < array[i])
			{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			print_array(array, size);
			}
		}
	}
}
