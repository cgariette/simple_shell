#include "shell.h"

/**
 * _execute - executes the commands
 * @argv: arguments given
 * Return: Nothing
 */

void _execute(char **argv)
{
	pid_t pid;
	int val, status, argc;
	extern char **environ;

	pid = fork();
	if (pid == 0)
	{
		val = execve(argv[0], argv, environ);
		if (val == -1)
			perror("Error");
	}
	else
		wait(&status);
	}
	}
