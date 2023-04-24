#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void swap(int *, int *);
int gap_calculator(size_t);
int find_max(int *, size_t);
void initialize_count_arr(int *, int);
void print_count_arr(int *, int);
int split_arrange_arr(int *, int, int, size_t);
void recursive_sort(int *, int, int, size_t);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif /*SORT_T*/
