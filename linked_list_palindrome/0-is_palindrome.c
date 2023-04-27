#include <stdio.h>
#include "lists.h"

/**
 * list_len - Returns the number of elements in a linked list_t list
 * @h : head node of each list_t
 *
 * Return: number of elements
 */

size_t list_len(const listint_t *h)
{
	unsigned int i = 0;

	if (h == NULL)
		return (0);

	while (h->next != NULL)
	{
		i++;
		h = h->next;
	}

	return (i + 1); /* to contemplate the last node */
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head : th first node
 * Return: 1 if it is a palindrome, 0 otherwise
 * Note: an empty list is considered a palindrome :)
*/

int is_palindrome(listint_t **head)
{
	unsigned int length = list_len(*head);
	int numbers[length];
	listint_t *aux;
	unsigned int i, j;

	/* Check if head is an empty linked list or has 1 element*/
	if (!length || length == 1)
		return (1);

	/* Save the element in an array */
	for (i = 0; *head != NULL; i++)
	{
		aux = *head;
		numbers[i] = aux->n;
		*head = aux->next;
	}

	/* Compare the elements with the reverse version of the list */
	for (i = 0, j = length - 1; i <= (length / 2); i++, j--)
	{
		if (numbers[i] != numbers[j])
			return (0);
	}

	/* At this point we checked all the list :) */
	return (1);
}
