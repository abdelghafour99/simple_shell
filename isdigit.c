#include "shell.h"

/**
 * _isdigit - checks if a character is a digit
 * @c: character
 * Return: 1 if digit else 0
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
