#include "shell.h"

/**
 * _token - get token from the input
 * @str: string to be parsed
 * @argv: arguments to be derived
 * @argc: number of arguments
 * Return: NOTHING
 */
void _token(char *str, char **argv, int argc)
{
	char *token = strtok(str, " \n");

	while (token)
	{
		argv[argc] = token;
		argc++;
		token = strtok(NULL, " \n");
	}
	argv[argc] = NULL;
}
