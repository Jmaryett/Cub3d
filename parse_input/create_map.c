#include "../cub.h"

static void	check_valid_after_parse(t_all *all, char **map)
{
	check_text_struct(all);
	//printf("No sega\n");
	check_ceiling_struct(all->ceiling.ceiling_color, all);
	check_floor_struct(all->floor.floor_color, all);
	//printf("in ceiling r - %d g - %d b - %d\n", all->ceiling.ceiling_r, all->ceiling.ceiling_g, all->ceiling.ceiling_b);
	//printf("in floor r - %d g - %d b - %d\n", all->floor.floor_r, all->floor.floor_g, all->floor.floor_b);
	check_if_map_is_valid(map, &all->plr);
	//printf("%s\n", all->text.path_east);
	//check_valid_map();
}

void	create_map(t_list *map_head, int size, t_all *all)
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
		map[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	// map[i] = NULL;
	//for (int i = 0; map[i]; i++)
	//	printf("after checking %s\n", map[i]);
	//printf("%s\n", all->text.path_east);
	check_valid_after_parse(all, map);
	all->map = map;
	//i = 0;
	// while(map[i]) {
	// 	free(map[i]);
	// 	i++;
	// }
	// free(map);
}
