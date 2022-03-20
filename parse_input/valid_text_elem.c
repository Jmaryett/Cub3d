/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_text_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:39:58 by jmaryett          #+#    #+#             */
/*   Updated: 2022/03/20 16:16:19 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	valid_color(char *s, t_all *all, int i)
{
	if (s[i] == 'C')
	{
		if (all->ceiling.ceiling_color)
			errors("Error\nToo many ceiling colors!\n");
		all->ceiling.ceiling_color = s;
	}
	else if (s[i] == 'F')
	{
		if (all->floor.floor_color)
			errors("Error\nToo many floor colors!\n");
		all->floor.floor_color = s;
	}
	else
		errors("Error\nNot enough or wrong elements!\n");
}

static void	valid_text_add(char *s, t_all *all, int i)
{
	if (s[i] == 'S' && s[i + 1] == 'O')
	{
		if (all->text.path_south)
			errors("Error\nToo many south textures paths!\n");
		all->text.path_south = ft_strdup(s);
	}
	else if (s[i] == 'E' && s[i + 1] == 'A')
	{
		if (all->text.path_east)
			errors("Error\nToo many east textures paths!\n");
		all->text.path_east = ft_strdup(s);
	}
	else
		valid_color(s, all, i);
}

void	valid_text(char *s, t_all *all, int i)
{
	if (s[i] == 'N' && s[i + 1] == 'O')
	{
		if (all->text.path_north)
			errors("Error\nToo many north textures paths!\n");
		all->text.path_north = ft_strdup(s);
	}
	else if (s[i] == 'W' && s[i + 1] == 'E')
	{
		if (all->text.path_west)
			errors("Error\nToo many west textures paths!\n");
		all->text.path_west = ft_strdup(s);
	}
	valid_text_add(s, all, i);
}
