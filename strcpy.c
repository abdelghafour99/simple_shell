#include "shell.h"

/**
 * _strcpy - copies the string
 * @dest: destination
 * @src: source
 * Return: dest
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */

char *_strcpy(char *dest, const char *src)
{
	char *s = dest;

	while (*src != '\0')
	{
		*s++ = *src++;
	}
	*s = '\0';
	return (dest);
}
