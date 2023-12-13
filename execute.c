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
	/*char  **env;*/
	pid = fork();
	if (pid == 0)
	{
		/*env = _getpath(argc, argv);*/
		val = execve(argv[0], argv, NULL);
		if (val == -1)
			perror("Error");
	}
	else
		wait(&status);
}
