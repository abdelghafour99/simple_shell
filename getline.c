#include "shell.h"
/**
 * _getline - Reads a line of input from stdin
 * @storage_ptr: pointer
 * @size_storage: size
 * @stream: stream
 * Return: 0
 *
 * Made byNoureddine Oubourhim, Abdelghafour Oussi
 */
ssize_t _getline(char **storage_ptr, size_t *size_storage, FILE *stream)
{
	ssize_t line_length = 0, starting_input = 0;
	char *storage = NULL, curr_char = ' ';

	if (starting_input == 0)
		fflush(stream);
	else
		return (-1);
	storage = malloc(STORAGE_SIZE * sizeof(char));
	if (storage == NULL)
		return (-1);
	while (curr_char != '\n')
	{
		if (!read_from_input(&curr_char))
		{
			free(storage);
			exit(EXIT_SUCCESS);
		}
		if (starting_input >= STORAGE_SIZE)
			storage = _realloc(storage, starting_input + 1);
		storage[starting_input++] = curr_char;
	}
	storage[starting_input] = '\0';
	edit_buff(storage_ptr, size_storage, storage, starting_input);
	line_length = starting_input;
	if (starting_input != 0)
		starting_input = 0;
	return (line_length);
}
