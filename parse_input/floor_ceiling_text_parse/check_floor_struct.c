/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:44:29 by jmaryett          #+#    #+#             */
/*   Updated: 2022/03/20 15:45:25 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

//30 - i cut the identifier first and left only what is after
static char	*cut_floor_identifier(char *str, int i)
{
	char	*tmp;
	int		len;

	if (!check_only_spaces(str))
		errors("Error\nNo colors!\n");
	while (str[i] == ' ')
		i++;
	if (!ft_isdigit(str[i]))
		errors("Error\nAfter identifier should be a positive digit!\n");
	len = i;
	while (str[len])
		len++;
	tmp = ft_substr(str, i, len);
	return (tmp);
}

void	check_floor_struct(char *colors, t_all *all)
{
	int		i;
	char	*tmp;

	i = skip_space(colors, ' ');
	if (colors[i] != 'F')
		errors("Error\nWrong or no identifier for the floor!\n");
	else
	{
		i += 1;
		if (colors[i] != ' ')
			errors("Error\nF should be accompanied by at least one space!\n");
		else
		{
			tmp = cut_floor_identifier(colors, i);
			check_floor_format(tmp, &all->floor);
			free (tmp);
			return ;
		}
	}
}
