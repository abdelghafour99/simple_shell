#include "shell.h"

/**
 * free_words - free words
 * @s: array of words
 * @n: number of words
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
void free_words(char **s, int n)
{
	int i = 0;

	if (!s)
		return;
	while (i < n)
	{
		if (s[i])
		{
			free(s[i]);
			s[i] = NULL;
		}
		i++;
	}
	free(s);
}
