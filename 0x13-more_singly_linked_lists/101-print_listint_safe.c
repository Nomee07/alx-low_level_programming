#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0, loop_detected = 0;
	const listint_t *slow = head, *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			loop_detected = 1;
			break;
		}
	}
	if (loop_detected)
	{
		printf("Infinite loop detected. Exiting with status 98\n");
		exit(98);
	}
	fast = head;

	while (fast != NULL)
	{
		printf("[%p] %d\n", (void *)fast, fast->n);
		fast = fast->next;
		count++;
	}

	return (count);
}
