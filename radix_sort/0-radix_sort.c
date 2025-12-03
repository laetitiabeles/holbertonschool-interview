#include "sort.h"
#include <stdlib.h>

/**
 * get_max - returns the maximum value in an array
 * @array: the array
 * @size: number of elements
 *
 * Return: maximum element or 0 if size == 0
 */
static int get_max(int *array, size_t size)
{
    size_t i;
    int max = 0;

    if (size == 0)
        return (0);
    max = array[0];
    for (i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return (max);
}

/**
 * counting_sort_by_digit - stable counting sort using a specific digit
 * @array: input array
 * @size: number of elements
 * @exp: 10^k representing the current digit
 * @buffer: buffer to store sorted output
 */
static void counting_sort_by_digit(int *array, size_t size, int exp, int *buffer)
{
    int count[10] = {0};
    size_t i;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size; i > 0; i--)
    {
        int idx = (array[i - 1] / exp) % 10;
        buffer[count[idx] - 1] = array[i - 1];
        count[idx]--;
    }
}

/**
 * radix_sort - sorts an array of integers in ascending order
 *              using the LSD Radix sort algorithm
 * @array: array to sort
 * @size: number of elements
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;
    int *buffer;

    if (!array || size < 2)
        return;

    max = get_max(array, size);
    buffer = malloc(sizeof(int) * size);
    if (!buffer)
        return;

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_by_digit(array, size, exp, buffer);

        /* copy buffer back to array */
        for (size_t i = 0; i < size; i++)
            array[i] = buffer[i];

        print_array(array, size);
    }

    free(buffer);
}
