#include "sort.h"

/**
 * shell_sort - sorts the given array
 * @array: The array to be sorted
 * @size1: Size of the array
 * Return: Nothing
 */

void shell_sort(int *array, size_t size1)
{
	int i, itrt, monitor, j, gap, size;

	size = size1;
	gap = gap_calculator(size);
	itrt = gap;
	while (itrt)
	{
	i = 0;
	while (i < itrt)
	{
		j = i;
		while (j + gap < size)
		{
			if (array[j] > array[j + gap])
			{
				swap(&array[j], &array[j + gap]);
			}
			monitor = 0;
			while (j - gap >= 0)
			{
				if (array[j] < array[j - gap])
				{
					swap(&array[j], &array[j - gap]);
					j = j - gap;
					monitor = 1;
				}
				else
					break;
			}
			if (!monitor)
				j = j + gap;
		}
		i++;
	}
	print_array(array, size);
	itrt = gap / 3;
	gap = itrt;
	}
}

/**
 * swap - swaps two given numbers
 * @num: First number.
 * @num2: Second number.
 * Return: Nothing
 */

void swap(int *num, int *num2)
{
	int tmp;

	/*printf("num: = %d\nnum2: %d\n", *num, *num2);*/
	tmp = *num;
	*num = *num2;
	*num2 = tmp;
}

/**
 * gap_calculator - finds the gap spacing
 * @size1: Size of the array
 * Return: gap size
 */

int gap_calculator(size_t size1)
{
	int gap1, size;

	size = (int) size1;
	gap1 = 1;
	while (gap1 < size)
		gap1 = gap1 * 3 + 1;
	gap1 = gap1 / 3;
	return (gap1);
}
