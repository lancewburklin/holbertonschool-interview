#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - Checks for a cycle in a linked list
 * @list: List to check
 * Return: 0 for no cycle, 1 otherwise
**/

int check_cycle(listint_t *list)
{
	listint_t *turtle = list;
	listint_t *hare = list;

	if (list == NULL)
		return (0);

	while (hare->next != NULL && hare->next->next != NULL)
	{
		turtle = turtle->next;
		hare = hare->next->next;
		if (turtle == hare)
			return (1);
	}
	return (0);
}
