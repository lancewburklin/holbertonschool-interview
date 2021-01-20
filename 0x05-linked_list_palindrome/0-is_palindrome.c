#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - Determines if a list is a palindrome
 * @head: Head of the linked list
 *
 * Return: 1 on success, 0 if not
*/

int is_palindrome(listint_t **head)
{
	if (head == NULL)
		return (1);
	return (is_palindrome_two(head, *head));
}

/**
 * is_palindrome_two - Recursively finds if list is palindrome
 * @left: Left check
 * @right: Right check
 *
 * Return: 1 if palindrome, or 0 if not
*/

int is_palindrome_two(listint_t **left, listint_t *right)
{
	if (right == NULL)
		return (1);

	if (is_palindrome_two(left, right->next) == 0)
		return (0);

	if (right->n == (*left)->n)
	{
		*left = (*left)->next;
		return (1);
	}
	else
	{
		*left = (*left)->next;
		return (0);
	}
}
