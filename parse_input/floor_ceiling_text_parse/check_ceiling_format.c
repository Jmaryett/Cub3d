/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ceiling_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:50:20 by jmaryett          #+#    #+#             */
/*   Updated: 2022/03/20 15:50:20 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

static int	fill_rgb(char *str, int flag, t_ceiling *ceiling, int i)
{
	if (ceiling->ceiling_r == -1)
	{
		ceiling->ceiling_r = ft_atoi_m(&str[i]);
		flag++;
	}
	else if (ceiling->ceiling_g == -1)
	{
		ceiling->ceiling_g = ft_atoi_m(&str[i]);
		flag++;
	}
	else if (ceiling->ceiling_b == -1)
	{
		ceiling->ceiling_b = ft_atoi_m(&str[i]);
		flag++;
	}
	return (flag);
}

int	move_i(char *s, int i)
{
	while (ft_isdigit(s[i]) && s[i])
		i++;
	return (i);
}

int	skip_space_in_s(char *s, int i)
{
	if (!s)
		return (0);
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (i);
}

void	check_ceiling_format(char *str, t_ceiling *ceiling)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		i = skip_space_in_s(str, i);
		if (!ft_isdigit(str[i]))
			errors("Error\nWrong color format!\n");
		flag = fill_rgb(str, flag, ceiling, i);
		i = move_i(str, i);
		i = skip_space_in_s(str, i);
		if (str[i] == ',' && flag != 3 && str[i + 1] != '\0')
		{
			i++;
			continue ;
		}
		else if (flag == 3 && str[i] == '\0')
			break ;
		else
			errors("Error\nWrong color format check_ceiling_format\n");
	}
}
