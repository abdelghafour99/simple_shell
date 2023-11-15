#include "shell.h"

/**
 * _memcpy - copies memory
 * @dest: destination
 * @src: source
 * @n: number
 * Return: dest
 *
 * Made byNoureddine Oubourhim, Abdelghafour Oussi
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *destt = dest;
	const unsigned char *srcc = src;
	size_t index = 0;

	while (index < n)
	{
		destt[index] = srcc[index];
		index++;
	}
	return (dest);
}
