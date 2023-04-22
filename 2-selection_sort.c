#include "sort.h"

/**
 * selection_sort - sorts the given array
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, addrs, tmp;
	int check, sgnl;

	while (i < size)
	{
		sgnl = 0;
		j = i;
		check = array[j];
		while (j < size)
		{
			if (array[j] < check)
			{
				sgnl = 1;
				check = array[j];
				addrs = j;
			}
			j++;
		}
		if (sgnl)
		{
			tmp = array[i];
			array[i] = array[addrs];
			array[addrs] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
