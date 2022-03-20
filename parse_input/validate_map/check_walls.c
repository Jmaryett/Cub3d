/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:55:47 by jmaryett          #+#    #+#             */
/*   Updated: 2022/03/20 16:18:33 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

//if last str is empty i check if pre-last consists of 1 and ' '
static void	check_walls_add(char **map, int i, int j, int len)
{
	(void)i;
	if (map[len - 1][0] == '\0')
	{	
		while (map[len - 2][j])
		{
			if (map[len - 2][j] != '1' && map[len - 2][j] != ' ')
				errors("Error\nWrong symbols in the last line check_walls_2\n");
			j++;
		}
		return ;
	}
	else if (!check_only_spaces(map[len - 1]))
		errors("Error\nOnly spaces in the last line of the map check_walls_3\n");
	while (map[len - 1][j])
	{
		if (map[len - 1][j] != '1' && map[len - 1][j] != ' ')
			errors("Error\nWrong symbols in the last line check_walls_4\n");
		j++;
	}
}

void	check_walls(char **map, int i, int j)
{
	int	len;

	len = 0;
	(void)i;
	while (map[len])
		len++;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
			errors("Error\nWrong symbols in the first line check_walls_1\n");
		j++;
	}
	j = 0;
	check_walls_add(map, i, j, len);
}
