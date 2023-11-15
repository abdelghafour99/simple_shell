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
	int final_result;

	if (!name || name[0] == '\0')
	{
		perror("unsetenv: invalid env name\n");
		return (-1);
	}
	final_result = unsetenv(name);
	if (final_result < 0)
		perror("unsetenv: failed to unset env\n");
	return (final_result);
}
