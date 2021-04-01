#include "search.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * linear_skip - Searches a linear skip list
 * @list: List to search
 * @value: Value to look for
 * Return: Node or NULL if fail
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express;

	if (list == NULL)
		return (NULL);
	express = list->express;
	while (express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		if (express->n > value || express->express == NULL)
		{
			if (express->n <= value)
			{
				list = express;
				while (express->next != NULL)
				{
					express = express->next;
				}
			}
			printf("Value found between indexes [%lu] and [%lu]\n",
			list->index, express->index);
			if (express->next == NULL)
				express = express->next;
			while (list != express)
			{
				printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
				if (list->n == value)
					return (list);
				list = list->next;
			}
			return (NULL);
		}
		else if (express->n == value)
		{
			return (express);
		}
		list = express;
		express = express->express;
	}
	return (NULL);
}
