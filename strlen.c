#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */

size_t _strlen(const char *s)
{
	size_t len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
