#include "sort.h"

/**
 * insertion_sort_list - sorts the given list
 * @list: linked list to be sorted
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *tmp2, *tmp3;

	tmp = *list;
	while (tmp != NULL)
	{
		if (tmp->next != NULL)
		{
		if (tmp->n > tmp->next->n)
		{
			tmp2 = tmp->next;
			tmp3 = tmp;
			tmp->next = tmp->next->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp;
			tmp2->next = tmp3;
			tmp2->prev = tmp3->prev;
			if (tmp3->prev != NULL)
				tmp3->prev->next = tmp2;
			tmp3->prev = tmp2;
			if (tmp2->prev != NULL)
				tmp = tmp2->prev;
			else
			{
				*list = tmp2;
				tmp = tmp2->next;
			}
			print_list(*list);
		}
		else
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
}
