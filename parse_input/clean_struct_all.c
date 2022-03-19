#include "../cub.h"

void	clean_struct_all(t_all *all)
{
	int	i;

	i = -1;
	if (all->text.path_east)
		free(all->text.path_east);
	if (all->text.path_west)
		free(all->text.path_west);
	if (all->text.path_north)
		free(all->text.path_north);
	if (all->text.path_south)
		free(all->text.path_south);
	if (all->map)
	{
		while(all->map[++i])
			free(all->map[i]);
	}
	free(all->map);
}
