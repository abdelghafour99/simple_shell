#include "shell.h"

/**
 * is_valid - checks if a string is valid
 * @s: the string to check
 * Return: 1 if valid else 0
 *
 * Made byNoureddine Oubourhim, Abdelghafour Oussi
 */
int is_valid(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (!isalnum(s[i]) && s[i] != '-' && s[i] != '_' && s[i] != '.')
			return (0);
		i++;
	}
	return (1);
}
