#include "shell.h"

/**
 * _strstr - locates a substring
 * @haystack: string
 * @needle: substring
 * Return: pointer
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
char *_strstr(const char *haystack, const char *needle)
{
	char *p1, *p2;

	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	while (*haystack != '\0')
	{
		p1 = (char *)haystack;
		p2 = (char *)needle;
		while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2)
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
