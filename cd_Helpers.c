#include "shell.h"

/**
 * env_vars - Gets the value of an environment variable.
 * @env_name: The name of the environment variable to get.
 * @env_pointer: The list of environment variables.
 * Return: The value of the environment variable.
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
char *env_vars(const char *env_name, char **env_pointer)
{
	char **the_env;

	for (the_env = env_pointer; *the_env != NULL; the_env++)
	{
		if (_strncmp(env_name, *the_env, _strlen(env_name)) == 0
		&& (*the_env)[_strlen(env_name)] == '=')
		{
			return (*the_env + _strlen(env_name) + 1);
		}
	}
	return (NULL);
}

/**
 * isError - Prints an error message.
 * @msg: The error message to print.
 * Return: void
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
void isError(const char *msg)
{
	printf("cd: %s\n", msg);
}

/**
 * get_dir - Gets the directory.
 * @init_p: The initial directory.
 * Return: The directory.
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
char *get_dir(const char *init_p)
{
	if (init_p == NULL)
		return (env_vars("HOME", environ));
	else if (_strcmp(init_p, "-") == 0)
		return (env_vars("OLDPWD", environ));
	else
		return ((char *)init_p);
}

/**
 * handle_cwd - Gets the current working directory.
 * Return: The current working directory.
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
char *handle_cwd()
{
	char *the_cwd;

	the_cwd = getcwd(NULL, 0);
	if (the_cwd == NULL)
		perror("cd");
	return (the_cwd);
}

/**
 * switch_current_dir - Changes the current working directory.
 * @dir: The new directory.
 * Return: 0 on success, -1 on failure.
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
int switch_current_dir(const char *dir)
{
	int ret = chdir(dir);

	if (ret != 0)
		return (-1);

	return (0);
}
