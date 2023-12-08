#include "shell.h"

int main(void)
{
	int argc = 0, count = 0;
	size_t n = 0;
        ssize_t line;
	char *str = NULL, *string = NULL, *token = NULL;
	char *delim = " \n";
	char **argv = NULL;

	while (1)
	{
		_putchar('$');
        	line = getline(&str, &n, stdin);

        	if (line == -1)
        	{
                	perror("Error");
                	free(str);
                	return (-1);
		}
		string = strdup(str);
		token = strtok(str, delim); 

		while(token)
		{
			printf("%s\n", token);
			argc++;
			token = strtok(NULL, delim);
		}
		printf(">>>>> %d \n", argc);

		argv = malloc(sizeof(char *) * argc);
		token = strtok(string, delim);

		while(token)	
		{
			argv[count] = token;
			printf(">>>>> %s \n", argv[count]);
			count++;
			token= strtok(NULL, delim);
		}
		printf("%d\n", count);
		argv[count] = NULL;
		argc = 0;
		count = 0;

	}

	free(str), free(string), free(argv);
        return (0);
}
