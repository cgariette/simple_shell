#include "shell.h"

void _execute(char **argv)
{
	pid_t pid;
	int val, status;

	pid = fork();
	
	if (pid == 0)
	{
		val = execve(argv[0], argv, NULL);
		if (val == -1)
			perror("Error");
	}
	else
		wait(&status);
}
