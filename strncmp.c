#include "shell.h"

/**
 * _strncmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number
 * Return: result
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index = 0;

	while (index < n)
	{
		if (s1[index] != s2[index])
			return ((s1[index] < s2[index]) ? -1 : 1);
		else if (s1[index] == '\0')
			return (0);
		index++;
	}
	return (0);
}
