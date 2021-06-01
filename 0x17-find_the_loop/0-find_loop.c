#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * find_listint_loop - Find the loop in a list
 * @head: Head of the list
 * 
 * Return: The loop node, or NULL for no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
    listint_t *turtle = head;
    listint_t *hare = head;
    if (head == NULL)
        return (NULL);
    while (turtle->next != NULL && hare->next->next != NULL)
    {
        printf("%d\n", turtle->n);
        hare = hare->next->next;
        turtle = turtle->next;
        if (hare == turtle)
            break;
    }
    if (turtle != hare)
        return (NULL);
    turtle = head;
    while (turtle != hare) {
        turtle = turtle->next;
        hare = hare->next;
    }
    return (hare);
}
