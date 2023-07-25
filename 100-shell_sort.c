#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gp;

	if (array == NULL || size < 2)
		return;

	for (gp = 1; gp < (size / 3);)
		gp = gp * 3 + 1;

	for (; gp >= 1; gp /= 3)
	{
		for (i = gp; i < size; i++)
		{
			j = i;
			while (j >= gp && array[j - gp] > array[j])
			{
				swap_ints(array + j, array + (j - gp));
				j -= gp;
			}
		}
		print_array(array, size);
	}
}
