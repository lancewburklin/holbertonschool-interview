#include "regex.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * regex_match - Simple regex function
 * @str: String to check
 * @pattern: Pattern to compare
 *
 * Return: 1 for yes, 0 for now
*/

int regex_match(char const *str, char const *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return (1);
	if (*pattern == '.' || *str == *pattern)
		return (regex_match(str + 1, pattern + 1));
	if (*pattern == '*')
		return (regex_match(str, pattern + 1) || regex_match(str + 1, pattern));
	return (0);
}
