#include "../cub.h"

static void	check_valid_after_parse(t_all *all, char **map)
{
	check_text_struct(all);
	printf("No sega\n");
	check_ceiling_struct(all->ceiling.ceiling_color, all);
	check_floor_struct(all->floor.floor_color, all);
	//printf("in ceiling r - %d, g - %d, b - %d\n", all->colors->ceiling_r, all->colors->ceiling_g, all->colors->ceiling_b);
	//printf("in floor r - %d, g - %d, b - %d\n", all->colors->floor_r, all->colors->floor_g, all->colors->floor_b);
	(void)map;
	//check_valid_map();
}

void	process_map(t_list *map_head, int size, t_all *all)
{
	char	**map;
	t_list	*tmp;
	int		i;

	map = ft_calloc(size + 1, sizeof(char *));
	if (!map)
		errors("Error\nTroubles with mallocing map\n");
	tmp = map_head;
	i = -1;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	//for (int i = 0; map[i]; i++)
		//printf("after checking %s\n", map[i]);
	check_valid_after_parse(all, map);
}
