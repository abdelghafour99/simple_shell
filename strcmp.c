#include "shell.h"

/**
 * _strcmp - Compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: result
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
int _strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
