/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:36:37 by jmaryett          #+#    #+#             */
/*   Updated: 2022/03/20 15:36:37 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

//check if str in list is starting with 0 or 1 that defines it as a map start
static int	is_map(t_list *tmp)
{
	t_list	*tmp_2;
	char	*content;
	int		i;

	i = -1;
	tmp_2 = tmp;
	content = tmp_2->content;
	while (content[++i])
	{
		while (content[i] == ' ' || content[i] == '\t')
			i++;
		if (content[i] == '1')
			return (1);
		else
			return (0);
	}
	return (0);
}

static void	proc_elem_add(int count, char *s, t_all *all, int i)
{
	count = 1;
	valid_text(s, all, i);
}

static void	process_elements(char *s, t_all *all)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if (s[i] == 'C' || s[i] == 'F' || s[i] == 'N'
			|| s[i] == 'W' || s[i] == 'E' || s[i] == 'S')
		{
			proc_elem_add(count, s, all, i);
			break ;
		}
		else if (s[i] == ' ' || s[i] == '\t')
		{
			i++;
			continue ;
		}
		i++;
	}
	if (count == 0)
		errors("Error\nNot enough/wrong elements in map!\n");
}

//61 - if str contains only spaces we skip it
//63 - if we find map then we stop processing in that func,
//create map and return filled structs and map
//67 - we fill map
static int	check_str_content(char *content, t_all *all, t_list *tmp)
{
	if (!check_only_spaces(content))
		return (0);
	else if (is_map(tmp))
	{
		if (!check_if_all_elems_filled(all))
			errors("Error\nNot enough elements!\n");
		create_map(tmp, ft_lstsize(tmp), all);
		return (1);
	}
	process_elements(content, all);
	return (0);
}

void	check_list_content(t_list **head, t_all *all)
{
	int		map_flag;
	t_list	*tmp;

	map_flag = 1;
	tmp = *head;
	while (tmp)
	{
		map_flag = check_str_content(tmp->content, all, tmp);
		if (map_flag == 1)
			break ;
		tmp = tmp->next;
	}
	if (map_flag == 0)
		errors("Error\nNo map in the file\n");
}
