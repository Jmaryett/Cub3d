/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_map_is_valid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:07:10 by jmaryett          #+#    #+#             */
/*   Updated: 2022/03/20 16:17:30 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

static void	add_check_map_char(char **map, int i, int j)
{
	if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
		&& map[i][j] != 'S' && map[i][j] != 'W' && map[i][j] != 'E'
		&& map[i][j] != ' ')
		errors("Error\nWrong symbols in the map!\n");
}

static void	check_map_char_add(char **map, int i)
{
	if (map[i + 1] != NULL && !check_only_spaces(map[i]))
		errors("Error\nEmpty lines in map\n");
}

static void	check_pos_flag(int pos_flag)
{
	if (pos_flag == 0)
		errors("Error\nNo player in the map!\n");
}

void	check_map_char_empty_lines(char **map, int i, int j, t_plr *player)
{
	int	pos_flag;

	pos_flag = 0;
	while (map[i])
	{
		check_map_char_add(map, i);
		j = -1;
		while (map[i][++j])
		{
			add_check_map_char(map, i, j);
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (pos_flag != 0)
					errors("Error\nToo many player's position in map!\n");
				pos_flag = 1;
				player->x = j;
				player->y = i;
				player->dir = map[i][j];
				map[i][j] = '0';
			}
		}
		i++;
	}
	check_pos_flag(pos_flag);
}

void	check_if_map_is_valid(char **map, t_plr *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map || !*map)
		return ;
	check_map_char_empty_lines(map, i, j, player);
	check_walls(map, i, j);
	check_how_map_filled(map, i, j);
}
