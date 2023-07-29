#include "philo.h"

int	terminate(char *err, int n)
{
	printf("%s", err);
	return (n);
}

int	main(int argc, char *argv[])
{
	t_args	args;

	if (argc != 5 && argc != 6)
		return (terminate(ERR_ARGC, 1));
	memset(&args, 0, sizeof(t_args));
	if (init(&args, argc, argv))
		return (terminate(ERR_ARGS, 1));
	if (start_routine(&args, (&args)->philos))
		return (terminate(ERR_ROUTINE, 1));
	return (0);
}
