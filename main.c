#include "cub.h"

int	main(int ac, char **av)
{
	t_all		all;
	t_text_path	text;
	t_colors	colors;
	t_resol		resol;

	if (ac != 2)
		errors("Error\nWrong number of args!\n");
	init_all(&all, &text, &colors, &resol);
	check_input(av[1], &all);
	exit(0);
}
