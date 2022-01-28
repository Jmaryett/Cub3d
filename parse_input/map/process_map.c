#include "../../cub.h"

void	check_value_colors(t_colors *colors)
{
	// colors->floor_r = ft_atoi(colors->floor_correct[0]);
	// colors->floor_g = ft_atoi(colors->floor_correct[1]);
	// colors->floor_g = ft_atoi(colors->floor_correct[2]);
	if (colors->floor_r > 255 || colors->floor_g > 255
		|| colors->floor_b > 255)
		errors("Error\nF color should be from 0 to 255\n");
	if (colors->floor_r < 0 || colors->floor_g < 0
		|| colors->floor_b < 0)
		errors("Error\nF color should be from 0 to 255\n");
	// colors->ceiling_r = ft_atoi(colors->ceiling_correct[0]);
	// colors->ceiling_r = ft_atoi(colors->ceiling_correct[1]);
	// colors->ceiling_r = ft_atoi(colors->ceiling_correct[2]);
	if (colors->ceiling_r > 255 || colors->ceiling_g > 255
		|| colors->ceiling_b > 255)
		errors("Error\nC color should be from 0 to 255\n");
	if (colors->ceiling_r < 0 || colors->ceiling_g < 0
		|| colors->ceiling_b < 0)
		errors("Error\nC color should be from 0 to 255\n");
}

static void	check_valid_after_parse(t_all *all, char **map)
{
	check_text_struct(all);
	check_ceiling_struct(all->colors->ceiling_color, all);
	check_floor_struct(all->colors->floor_color, all);
	printf("in ceiling r - %d, g - %d, b - %d\n", all->colors->ceiling_r, all->colors->ceiling_g, all->colors->ceiling_b);
	printf("in floor r - %d, g - %d, b - %d\n", all->colors->floor_r, all->colors->floor_g, all->colors->floor_b);
	check_value_colors(all->colors);
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
