#include <stdio.h>
#include "palindrome.h"

/**
  * is_palindrome - Recursively decided if a number is a palindrome
  * @n: Number in inspect
  * Return: 1 if true, 0 if not
**/

int is_palindrome(unsigned long n)
{
	unsigned long reverse;

	reverse = palindrome_recurse(n);

	if (reverse == n)
		return (1);
	return (0);
}

/**
  * palindrome_recurse - Recursively decided if a number is a palindrome
  * @n: Number in inspect
  * Return: The reverse of the number
**/

unsigned long palindrome_recurse(unsigned long n)
{
	static unsigned long reverse, remainder;

	if (n != 0)
	{
		remainder = n % 10;
		reverse = reverse * 10 + remainder;
		palindrome_recurse(n / 10);
	}
	return (reverse);
}
