#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: singly linked list to check
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *slow_p = list, *fast_p = list;

	/* Check if list is empty */
	if (list == NULL)
		return (0);

	/*
	 * Implement Floyd’s Cycle-Finding Algorithm:
	 * Move one pointer(slow_p) by one and another pointer(fast_p) by two.
	 * If these pointers meet at the same node then there is a loop.
	 */
	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
			return (1);
	}
	return (0);
}
