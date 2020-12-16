#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* insert_node - Insers a node into a linked list
* @head: Head of the list
* @number: Number to put in the new node
* Return: The new node or NULL on fail
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return (new);
	}
	current = *head;
	if (new->n < current->n)
	{
		new->next = current;
		*head = new;
		return (new);
	}
	while (current->next != NULL)
	{
		if (current->n < number && current->next->n > number)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		else if (current->n == number)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		current = current->next;
	}
	current->next = new;
	new->next = NULL;
	return (new);
}
