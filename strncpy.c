#include "shell.h"

/**
 * _strncpy - copies a string
 * @dest: destination
 * @src: source
 * @n: number
 * Return: dest
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
char *_strncpy(char *dest, char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
