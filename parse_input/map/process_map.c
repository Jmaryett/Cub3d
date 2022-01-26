#include "../../cub.h"

static void	check_valid_elems(t_all *all)
{
	check_text_struct(all);
	//check_colors_struct(all->colors);
	//check_resolution_struct(all->resol);
}

static void	check_valid_after_parse(t_all *all, char **map)
{
	check_valid_elems(all);
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
	for (int i = 0; map[i]; i++)
		printf("after checking %s\n", map[i]);
	check_valid_after_parse(all, map);
}
