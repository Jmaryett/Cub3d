/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_struct_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:09:19 by jmaryett          #+#    #+#             */
/*   Updated: 2022/03/20 16:09:19 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	clean_struct_all(t_all *all)
{
	int	i;

	i = -1;
	if (all->text.path_east)
		free(all->text.path_east);
	if (all->text.path_west)
		free(all->text.path_west);
	if (all->text.path_north)
		free(all->text.path_north);
	if (all->text.path_south)
		free(all->text.path_south);
	if (all->map)
	{
		while (all->map[++i])
			free(all->map[i]);
	}
	free(all->map);
}
