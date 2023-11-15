#include "shell.h"
/**
 * get_dir_p - gets the directory path
 * @path: path
 * @cmd: command
 * Return: result
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
char *get_dir_p(const char *path, const char *cmd)
{
	char *dir_path = malloc(_strlen(path) + _strlen(cmd) + 2);

	if (!dir_path)
		return (NULL);
	_strcpy(dir_path, path);
	_strcat(dir_path, "/");
	_strcat(dir_path, cmd);
	return (dir_path);
}
