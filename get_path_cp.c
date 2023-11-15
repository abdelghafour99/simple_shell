#include "shell.h"

/**
 * get_p_cp - Gets the value of the "PATH" environment variable.
 * Return: The value of the "PATH" environment variable.
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
char *get_p_cp()
{
	char *path = getenv("PATH");
	char *path_cp;

	if (!path)
		return (NULL);
	path_cp = _strdup(path);
	if (!path_cp)
		return (NULL);
	return (path_cp);
}
