/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_how_map_filled.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:58:54 by jmaryett          #+#    #+#             */
/*   Updated: 2022/03/20 16:08:49 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

//20-if before space was not 1
//25-if above and aside isn't 1 or space
static int	check_spaces_in_map(char **map, int i, int j)
{
	if (j != 0 && map[i][j - 1] != '1')
		errors("Error\nWrong map format check_spaces_in_map_1\n");
	{
		if (i != 0)
			if (map[i - 1][j] != ' ' && map[i - 1][j] != '1'
				&& (map[i - 1][j - 1] == '0' || map[i - 1][j + 1] == '0'))
				errors("Error\nWrong map format check_spaces_in_map_2\n");
		if (map[i + 1] && map[i + 1][0] != '\0')
			if (map[i + 1][j - 1] == '0' || map[i + 1][j + 1] == '0')
				errors("Error\nWrong map format check_spaces_in_map_3\n");
		j++;
	}
	if (map[i][j] != '1')
		errors("Error\nWrong map format check_spaces_in_map_3\n");
	return (j);
}

// 45 - if before zero was not 1
// 48 - if above isn't 1 or 0
// 50 - if below isn't 1 or 0
//55- if on diagonal above and below zero isn't 1 or 0
//60 - if after 0 isn't 1??
static int	check_zero_in_map(char **map, int i, int j)
{
	if (j != 0 && map[i][j - 1] != '1')
		errors("Error\nWrong map format check_zero_in_map_1\n");
	while (map[i][j] == '0')
	{
		if (map[i - 1][j] != '1' && map[i - 1][j] != '0')
			errors("Error\nWrong map format check_zero_in_map_2\n");
		else if (map[i + 1][j] != '1' && map[i + 1][j] != '0')
			errors("Error\nWrong map format check_zero_in_map_4\n");
		else if ((map[i + 1][j - 1] != '1' && map[i + 1][j - 1] != '0')
			|| (map[i - 1][j - 1] != '1' && map[i - 1][j - 1] != '0')
			|| (map[i + 1][j + 1] != '1' && map[i + 1][j + 1] != '0')
			|| (map[i - 1][j + 1] != '1' && map[i - 1][j + 1] != '0'))
			errors("Error\nWrong map format check_zero_in_map_5\n");
		j++;
	}
	if (map[i][j] != '1')
		errors("Error\nWrong map format check_spaces_in_map_6\n");
	return (j);
}

// 70 - check if last line is empty
// 72 - if first symbol of the line is not 1 or space
// 85 - i check if line ends with 1
void	check_how_map_filled(char **map, int i, int j)
{
	while (map[i])
	{
		if (map[i + 1] == NULL && map[i][0] == '\0')
			break ;
		if (map[i][0] != '1' && map[i][0] != ' ')
			errors("Error\nWrong map format check_how_map_filled_1(str start)\n");
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				j = check_spaces_in_map(map, i, j);
			if (map[i][j] == '0')
				j = check_zero_in_map(map, i, j);
			j++;
		}
		if (map[i][j - 1] != '1')
			errors("Error\nWrong map format check_how_map_filled_2(str end)\n");
		i++;
	}
}
