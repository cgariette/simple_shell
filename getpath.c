#include "shell.h"

void _getpath(char **argv)
{
	unsigned int i;
	struct stat st;
	int path;
	
	i = 1;
	while(argv[i])
	{
		path = stat(argv[i], &st);
		if (path == 0)
			_execute(argv);
		else
			write(1, "./shell: No such file or directory\n", 34);
		i++;
	}
}
