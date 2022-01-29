#include "cub.h"

int	main(int ac, char **av)
{
	t_all		all;

	if (ac != 2)
		errors("Error\nWrong number of args!\n");
	init_all(&all);
	check_input(av[1], &all);
	exit(0);
}
