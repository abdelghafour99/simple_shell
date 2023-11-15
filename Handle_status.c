#include "shell.h"

/**
 * handle_exit_status - handles exit status
 * @arr: array of words
 * @ppt: prompt
 * @name: program name
 * @c: count
 * @n: number of words
 * Return: void
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
void handle_exit_status(char **arr, char *ppt, char *name, int c, int n)
{
	int ex_stat = 0;

	if (arr[1] != NULL)
	{
		if (_isdigit(arr[1][0]))
		{
			ex_stat = _atoi(arr[1]);
			free(ppt);
			free_words(arr, n);
			exit(ex_stat);
		}
		else
		{
			ex_err(arr, c, name);
			free(ppt);
			free_words(arr, n);
			exit(2);
		}
	}

	free(ppt);
	free_words(arr, n);
	exit(ex_stat);
}
