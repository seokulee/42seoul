#include "pipex.h"

int	main(int argc, char **argv)
{
	int	mode;

	(void) argc;
	(void) argv;
	mode = 0;
	mode |= F_OK;
	if (!access("test.txt", mode))
		printf("File is existing\n");
	else
		printf("File is not existing\n");
	mode &= 0;
	mode |= X_OK;
	if (!access("test.txt", mode))
		printf("File is excutable\n");
	else
		printf("File is not excutable\n");
	return (0);
}