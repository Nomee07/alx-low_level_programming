#include <stdio.h>
#include "lists.h"

/**
 * reverse_listint - Reverses a listnt_t linked list.
 * @head: Pointer to a pointer to the head of the list.
 *
 * Return: Pointer tot he first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *first, *rest;

	if (*head == NULL)
	{
		return (NULL);
	}
	first = *head;
	rest = first->next;

	if (rest == NULL)
	{
		return (first);
	}
	rest = reverse_listint(&rest);

	first->next->next = first;
	first->next = NULL;

	*head = rest;
	return (rest);
}
