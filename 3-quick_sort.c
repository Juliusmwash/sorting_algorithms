#include "sort.h"


/**
 * quick_sort - sorts the given array
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	recursive_sort(array, 0, size - 1, size);
}

/**
 * split_arrange_arr - splits the given array by rearranging the values
 * in referrence to the pivot
 * @array: array to be sorted
 * @min: minimum index of the sub array
 * @last: last index of the sub array
 * @size: size of the entire array
 * Return: nothing
 */

int split_arrange_arr(int *array, int min, int last, size_t size)
{
	int pivot, j, i, tmp;

	j = min;
	i = min;
	pivot = array[last];
	for (j = min; j < last; j++)
	{
		if (array[j] <= pivot)
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	tmp = array[i];
	array[i] = pivot;
	array[j] = tmp;
	if (i != j)
		print_array(array, size);

	return (i);
}

/**
 * recursive_sort - recursive function for sorting the array
 * @array: array to be sorted
 * @min: minimum index of the sub array
 * @last: last index of the sub array
 * @size: size of the array to be sorted
 * Return: Nothing
 */

void recursive_sort(int *array, int min, int last, size_t size)
{
	int min_last;

	if (min < last)
	{
		min_last = split_arrange_arr(array, min, last, size);
		recursive_sort(array, 0, min_last - 1, size);
		recursive_sort(array, min_last + 1, last, size);
	}
}
