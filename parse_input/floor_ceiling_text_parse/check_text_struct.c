/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_text_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:41:46 by jmaryett          #+#    #+#             */
/*   Updated: 2022/03/20 15:41:46 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

static void	check_west_struct(char *path_west)
{
	int	i;
	int	has_path;

	has_path = 0;
	i = skip_whitespace(path_west);
	if (path_west[i] != 'W' && path_west[i + 1] != 'E')
		errors("Error\nWrong identifier of the west texture!\n");
	else
	{
		i += 2;
		if (path_west[i] != ' ')
			errors("Error\nWE should be accompanied by at least one space!\n");
		while (path_west[i])
		{
			if (path_west[i] != ' ')
				has_path = 1;
			i++;
		}
	}
	if (has_path == 0)
		errors("Error\nNo west path!\n");
}

static void	check_east_struct(char *path_east)
{
	int	i;
	int	has_path;

	has_path = 0;
	i = skip_whitespace(path_east);
	if (path_east[i] != 'E' && path_east[i + 1] != 'A')
		errors("Error\nWrong identifier of the east texture!\n");
	else
	{
		i += 2;
		if (path_east[i] != ' ')
			errors("Error\nEA should be accompanied by at least one space!\n");
		while (path_east[i])
		{
			if (path_east[i] != ' ')
				has_path = 1;
			i++;
		}
	}
	if (has_path == 0)
		errors("Error\nNo east path!\n");
}

static void	check_south_struct(char *path_south)
{
	int	i;
	int	has_path;

	has_path = 0;
	i = skip_whitespace(path_south);
	if (path_south[i] != 'S' && path_south[i + 1] != 'O')
		errors("Error\nWrong identifier of the south texture!\n");
	else
	{
		i += 2;
		if (path_south[i] != ' ')
			errors("Error\nSO should be accompanied by at least one space!\n");
		while (path_south[i])
		{
			if (path_south[i] != ' ')
				has_path = 1;
			i++;
		}
	}
	if (has_path == 0)
		errors("Error\nNo south path!\n");
}

static void	check_north_struct(char *path_north)
{
	int	i;
	int	has_path;

	has_path = 0;
	i = skip_whitespace(path_north);
	if (path_north[i] != 'N' && path_north[i + 1] != 'O')
		errors("Error\nWrong identifier of the north texture!\n");
	else
	{
		i += 2;
		if (path_north[i] != ' ')
			errors("Error\nNO should be accompanied by at least one space!\n");
		while (path_north[i])
		{
			if (path_north[i] != ' ')
				has_path = 1;
			i++;
		}
	}
	if (has_path == 0)
		errors("Error\nNo north path!\n");
}

void	check_text_struct(t_all *all)
{
	check_north_struct(all->text.path_north);
	check_east_struct(all->text.path_east);
	check_west_struct(all->text.path_west);
	check_south_struct(all->text.path_south);
}
