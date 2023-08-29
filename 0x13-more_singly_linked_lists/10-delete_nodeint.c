#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at index.
 * @head: Pointer to a pointer tot the head of the list.
 * @index: The index of the node to delete.
 *
 * Return: 1 if it succeeded, or -1 if it failed.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int count = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = temp->next;
		free(temp);
		return (1);
	}
	current = *head;
	while (current != NULL)
	{
		if (count == index - 1)
		{
			if (current->next == NULL)
				return (-1);
			temp = current->next;
			current->next = temp->next;
			free(temp);
			return (1);
		}
		current = current->next;
		count++;
	}
	return (-1);
}
