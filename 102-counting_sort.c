#include "sort.h"

/**
 * counting_sort - sorts the given array.
 * @array: Array to be sorted.
 * @size1: Size of the array
 * Return: Nothing.
 */

void counting_sort(int *array, size_t size1)
{
	int max, i = 0, *count_arr, index, tmp, size;

	size = (int) size1;
	max = 1 + find_max(array, size);
	count_arr = malloc(sizeof(int) * max);
	if (count_arr == NULL)
		return;

	initialize_count_arr(count_arr, max);

	while (i < size)
	{
		count_arr[array[i]] += 1;
		i++;
	}
	i = 0;
	while (i < max)
	{
		if (i)
			count_arr[i] += count_arr[i - 1];
		i++;
	}

	print_array(count_arr, (size_t) max);

	i = 0;
	while (i < size)
	{
		index = count_arr[array[i]] - 1;
		tmp = array[index];
		array[index] = array[i];
		array[i] = tmp;
		i++;
	}
	free(count_arr);
}

/**
 * find_max - finds the maximum value in the array.
 * @array: Array to be sorted.
 * @size: The size of the array.
 * Return: max value in the array.
 */

int find_max(int *array, size_t size)
{
	int max;
	size_t i = 0;

	max = array[0];
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

/**
 * initialize_count_arr - initializes the count_arr.
 * @count_arr: Array to initialize.
 * @size: Size of the count_arr.
 * Return: Nothing
 */

void initialize_count_arr(int *count_arr, int size)
{
	int i = 0;

	while (i < size)
	{
		count_arr[i] = 0;
		i++;
	}
}
