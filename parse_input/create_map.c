/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:40:36 by jmaryett          #+#    #+#             */
/*   Updated: 2022/03/20 15:40:36 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	check_valid_after_parse(t_all *all, char **map)
{
	check_text_struct(all);
	check_ceiling_struct(all->ceiling.ceiling_color, all);
	check_floor_struct(all->floor.floor_color, all);
	check_if_map_is_valid(map, &all->plr);
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
	check_valid_after_parse(all, map);
	all->map = map;
}
