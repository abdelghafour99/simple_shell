#include "shell.h"

/**
 * _unsetenv - Unsets an environment variable.
 * @name: The name of the environment variable to unset.
 * Return: 0 on success, or -1.
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
int _unsetenv(const char *name)
{
	if (!name || name[0] == '\0')
	{
		perror("unsetenv: invalid env name\n");
		return (-1);
	}
	if (unsetenv(name) < 0)
		perror("unsetenv: failed to unset env\n");
	return (0);
}
