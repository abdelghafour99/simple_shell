#ifndef SHELL_H
#define SHELL_H

/***** MACROS *****/

#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFSIZE 10240
#define DELIMITER " \t\r\n\a"

/***LIBRARIES ***/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/******** String Handlers **********/

char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/*********** Memory Handlers ***********/

void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);

/****** Misc Functions *******/

char *_getline();
char *space(char *str);
char *enter(char *string);
void hashtag_handler(char *buff);
void prompt(void);
unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *delim);
int history(char *input);
char **separator(char *input);

/****** Argument Handlers ******/

void read_file(char *file, char **argv);
void treat_file(char *line, int count, FILE *fp, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);

/****** Parsed argument handlers *****/

char **parse_cmd(char *input);
int handle_builtin(char **cmd, int er);
int check_cmd(char **cmd, char *input, int c, char **argv);
void signal_to_handle(int sig);

/******* Error Handlers ******/

void print_error(char *input, int counter, char **argv);
void _prerror(char **argv, int c, char **cmd);
void error_file(char **argv, int c);

/****** Environment Handlers ******/

extern char **environ;
void create_envi(char **envi);
void free_env(char **env);

/****** Printers *****/

void print_number(unsigned int n);
void print_number_int(int n);
int print_echo(char **cmd);

/******* Path Finder *******/

int path_cmd(char **cmd);
char *build_cmd(char *token, char *value);
char *_getenv(char *name);

/******* Help Handlers *******/

void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);
void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
int display_help(char **cmd, __attribute__((unused)) int st);

/****** Built-in Command Handlers ******/

int check_builtin(char **cmd);
int handle_builtin(char **cmd, int st);
void exit_bul(char **cmd, char *input, char **argv, int c, int stat);
int change_dir(char **cmd, __attribute__((unused)) int st);

/**
 * dis_env - Displays environment
 * @cmd: Parsed command
 * @st: Status of last command executed
 * Return: 0 on success
 */
int dis_env(__attribute__((unused)) char **cmd,
			__attribute__((unused)) int st);
int echo_bul(char **cmd, int st);

/**
 * history_dis - display history of user input on simple_shell
 * @c: Parsed command
 * @st: Status of last command executed
 * Return: 0 on success
 */
int history_dis(__attribute__((unused)) char **c,
				__attribute__((unused)) int st);

/****** Built-in Struct *****/

/**
 * struct _builtin - Defines a struct that conatins built-in commands
 * with their respective implementation functions
 * @command: - Built-in command
 * @function: - Pointer to custom functions that have
 * similar functionalities as the built-in commands
 */

typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

#endif /*SHELL_H*/
