#include "../cub.h"

int	check_if_all_elems_filled(t_all *all)
{
	//printf("floor = %s\n", all->floor.floor_color);
	//printf("ceiling = %s\n", all->ceiling.ceiling_color);
	if (!all->ceiling.ceiling_color || !all->floor.floor_color)
		return (0);
	else if (!all->text.path_east || !all->text.path_west
		|| !all->text.path_south || !all->text.path_north)
		return (0);
	// else if (!all->resol->resolution)
	// 	return (0);
	return (1);
}
