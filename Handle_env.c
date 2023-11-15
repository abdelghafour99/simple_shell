#include "shell.h"

/**
 * handle_env - handles env command
 * Return: void
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
void handle_env(void)
{
	char **env_pointer = environ;

	while (*env_pointer)
	{
		printf("%s\n", *env_pointer);
		env_pointer++;
	}
}
