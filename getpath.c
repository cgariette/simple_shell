#include "shell.h"

void _getpath(int argc, char **argv)
{
	struct stat st;
	int path;
	
	while(argv[argc] != NULL)
	{
		path = stat(argv[argc], &st);
		if (path == 0)
			_execute(argv);
		else
			write(1, "./shell: No such file or directory\n", 36);
		argc++;
	}
}
