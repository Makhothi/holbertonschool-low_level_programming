#include "sort.h"

/**
 * partition - sort the partitions
 * @array: array to be sorted
 * @low: lowest index of the partition to be sorted (inclusive)
 * @high: highest index of the partition to be sorted (inclusive)
 * @size: size of the array to be sorted
 *
 * Return: index of the new partition
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot = low;
	int swap;

	while (pivot < high)
	{
		if (array[pivot] < array[high])
		{
			if (low != pivot)
			{
				swap = array[pivot];
				array[pivot] = array[low];
				array[low] = swap;
				print_array(array, size);
			}
			low += 1;
		}
		pivot += 1;
	}
	if (array[low] != array[high])
	{
		swap = array[high];
		array[high] = array[low];
		array[low] = swap;
		print_array(array, size);
	}
	return (low);
}



/**
 * quicksort_part - sorts two partition of an array of integers
 * @array: array to be sorted
 * @low: lowest index of the partition to be sorted (inclusive)
 * @high: highest index of the partition to be sorted (inclusive)
 * @size: size of the array to be sorted
 */
void quicksort_part(int *array, ssize_t low, ssize_t high, size_t size)
{
	size_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort_part(array, low, pivot - 1, size);
		quicksort_part(array, pivot + 1, high, size);
	}
}


/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_part(array, 0, size - 1, size);
}
