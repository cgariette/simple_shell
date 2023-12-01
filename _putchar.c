#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: character to print
 *
 * Return: 1 if successful
 * -1 if there is an error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
