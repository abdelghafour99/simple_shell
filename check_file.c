#include "shell.h"
/**
 * check_file - checks if a file exists
 * @path: path
 * Return: 1 if exists else 0
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
int check_file(const char *path)
{
	struct stat buffer;

	if (stat(path, &buffer) != 0)
		return (0);
	return (1);
}
