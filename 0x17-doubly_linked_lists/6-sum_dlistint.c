#include <stddef.h>
#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data
 * @head: Pointer to the head of the list
 * Return: Sum of all the data in the list, or 0 if empty
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}
