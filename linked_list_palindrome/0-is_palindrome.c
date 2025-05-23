#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - check if a linked list composed of integer is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	/* Get linked list len */
	int len = 0;
	listint_t *current;

	if (head == NULL)
		return (0);

	current = *head;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}

	/* Copy linked list in an array */
	int list_copy[len];
	current = *head;
	int i = 0;

	while (current != NULL)
	{
		list_copy[i] = current->n;
		current = current->next;
		i++;
	}
	int start = 0;
	int end = len - 1;
	int is_palindrome = 1;

	for (int i = 0; i < len; i++)
	{
		if (list_copy[start] != list_copy[end])
		{
			is_palindrome = 0;
			return (is_palindrome);
		}
		start++;
		end--;
	}
	return (is_palindrome);
}