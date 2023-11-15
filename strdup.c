#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter
 * @s: string
 * Return: pointer
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
char *_strdup(const char *s)
{
	size_t len = _strlen(s), i;
	char *duplicat = malloc(len + 1);

	if (duplicat)
	{
		for (i = 0; i < len; i++)
			duplicat[i] = s[i];
		duplicat[len] = '\0';
	}
	return (duplicat);
}
