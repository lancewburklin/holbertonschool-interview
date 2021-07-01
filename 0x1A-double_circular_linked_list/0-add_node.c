#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Add a node to the end of the list
 * @list: List to add to
 * @str: String to add
 * Return: The new node
*/

List *add_node_end(List **list, char *str)
{
	List *newNode;

	newNode = malloc(sizeof(List));
	if (newNode == NULL)
		return (NULL);

	newNode->str = strdup(str);
	if (newNode->str == NULL)
		return (NULL);
	if (*list == NULL)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		(*list) = newNode;
		return (newNode);
	}
	else
	{
		newNode->next = (*list);
		newNode->prev = (*list)->prev;
		newNode->prev->next = newNode;
		(*list)->prev = newNode;
	}
	return (newNode);
}

/**
 * add_node_begin - Add a node to the beginning
 * @list: list to add to
 * @str: String to put on node
 * Return: The new node
*/

List *add_node_begin(List **list, char *str)
{
	List *newNode, *tmp;

	tmp = (*list);
	newNode = malloc(sizeof(List));
	if (newNode == NULL)
		return (NULL);

	newNode->str = strdup(str);
	if (newNode->str == NULL)
		return (NULL);
	if (*list == NULL)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		(*list) = newNode;
		return (newNode);
	}
	else
	{
		while (tmp)
		{
			tmp = tmp->next;
			if (tmp == *list)
				break;
		}
		newNode->next = tmp;
		newNode->prev = tmp->prev;
		newNode->prev->next = newNode;
		tmp->prev = newNode;
		(*list) = newNode;
	}
	return (newNode);
}
