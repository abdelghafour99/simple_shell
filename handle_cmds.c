#include "shell.h"

/**
 * handle_multi_cmds_Helper - handle env, setenv, unsetenv cmds
 * @arr: the cmds provided
 * Return: 1 if one of the cmd is found or 0
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
int handle_multi_cmds_Helper(char **arr)
{
	char *cmd = arr[0];

	if (_strcmp(cmd, "alias") == 0)
	{
		exec_alias(arr);
		return (1);
	}
	else if (_strcmp(cmd, "unalias") == 0)
	{
		exec_alias(arr);
		return (1);
	}
	else if (_strcmp(cmd, "simple_shell") == 0)
	{
		char *filename = arr[1];

		run_commands_from_file(filename);
		return (1);
	}
	return (0);
}
/**
 * handle_multi_cmds - handle env, setenv, unsetenv cmds, handle cd, alias
 * @arr: the cmds provided
 * @ppt: user input
 * @name: program name
 * @cnt: counter
 * @n: number of cmds
 * Return: 1 if one of the cmd is found or 0
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
int handle_multi_cmds(char **arr, char *ppt, char *name, int cnt, int n)
{
	char *cmd = arr[0];
	int cmd_was_handled = 0;
	(void)name, (void)cnt, (void)n, (void)ppt;

	if (_strcmp(cmd, "env") == 0)
	{
		handle_env();
		cmd_was_handled = 1;
	}
	else if (_strcmp(cmd, "setenv") == 0)
	{
		if (arr[1] && arr[2])
			_setenv(arr[1], arr[2], 1);
		else
		{
			perror("Usage: setenv VARIABLE VALUE\n");
		}
		cmd_was_handled = 1;
	}
	else if (_strcmp(cmd, "unsetenv") == 0)
	{
		if (arr[1])
			_unsetenv(arr[1]);
		else
		{
			perror("Usage: setenv VARIABLE VALUE\n");
		}
		cmd_was_handled = 1;
	}
	else if (_strcmp(cmd, "cd") == 0)
	{
		handle_cd(arr);
		cmd_was_handled = 1;
	}
	else if (handle_multi_cmds_Helper(arr) == 1)
	{
		cmd_was_handled = 1;
	}
	return (cmd_was_handled);
}
