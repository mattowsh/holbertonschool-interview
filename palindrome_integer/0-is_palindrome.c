#include "palindrome.h"
#include <stdio.h>
#include <string.h>

/**
 * is_palindrome - Checks whether or not a given unsigned integer
 * is a palindrome
 * @n: the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
*/

int is_palindrome(unsigned long n)
{
	unsigned int i, j;
	char str[10];

	sprintf(str, "%ld", n);

	for (i = 0, j = strlen(str) - 1; i <= (strlen(str) / 2); i++, j--)
	{
		if (str[i] != str[j])
			return (0);
	}

	return (1);
}
