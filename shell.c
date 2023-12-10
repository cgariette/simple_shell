#include "shell.h"

int main(void)
{
	int argc = 0, val, status;
	size_t n = 0;
        ssize_t line;
	char *str = NULL, *string = NULL, *token = NULL;
	char *delim = " \n";
	char **argv = NULL;
	pid_t pid;

	while (1)
	{
		write(1, "shell$ ", 7);
        	line = getline(&str, &n, stdin);

        	if (line == -1)
        	{
                	perror("Error");
                	free(str);
                	return (-1);
		}
		string = strdup(str);
		token = strtok(str, delim); 
		argv = malloc(sizeof(char *) * argc);

		while(token)
		{
			argv[argc] = token;
			argc++;
			token = strtok(NULL, delim);
		}
		argv[argc] = NULL;
		pid = fork();
		
		execmd(argv);

		if (pid == 0)
		{
			val = execve(argv[0], argv, NULL);
			if(val == -1)
			{	
				perror("Error");
			}
		}
		else
		{
			wait(&status);
		}
		argc = 0;
		free(argv);
	}
        return (0);
}
