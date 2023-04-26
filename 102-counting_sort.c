#include "sort.h"

/**
 * counting_sort - sorts the given array.
 * @array: Array to be sorted.
 * @size1: Size of the array
 * Return: Nothing.
 */

void counting_sort(int *array, size_t size1)
{
	int max, i = 0, *count_arr, size;

	if (size1 < 2 || array == NULL)
		return;
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
	final_move(count_arr, array, size1);
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

/**
 * final_move - rearranges the data in the array.
 * @count_arr: Array with the counted data.
 * @array: The array to sort.
 * @size1: The size of the array.
 * Return: Nothing.
 */

void final_move(int *count_arr, int *array, size_t size1)
{
	int *tmp, size, index, i = 0;

	size = (int) size1;
	tmp = malloc(size * sizeof(int));
	if (tmp == NULL)
		return;
	for (; i < size; i++)
		tmp[i] = 0;
	i = 0;
	while (i < size)
	{
		index = count_arr[array[i]] - 1;
		if (tmp[index] == array[i] && array[i])
		{
			while (index)
			{
				if (tmp[index] == array[i])
					index -= 1;
				else
					break;
			}
		}
		tmp[index] = array[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		array[i] = tmp[i];
		i++;
	}
	free(tmp);
}
