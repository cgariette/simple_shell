#include "shell.h"

/**
 * _prompt - prints a prompt
 *
 */
void _prompt(void)
{
	size_t n = 10;
	char * buffer = NULL;

	_putchar('$');

	getline(&buffer, &n, stdin);

	free (buffer);

}

int main()
{
	while (1)
	{
		_prompt();
	}
	return (0);
}
