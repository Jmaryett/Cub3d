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
		while (content[i] == ' ')
			i++;
		if (content[i] == '1')
			return (1);
		else
			return (0);
	}
	return (0);
}

static void	process_elements(char *s, t_all *all)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i] == 'C' || s[i] == 'F' || /* s[i] == 'R' || */ s[i] == 'N'
			|| s[i] == 'W' || s[i] == 'E' || s[i] == 'S')
		{
			count = 1;
			valid_text(s, all, i);
			break ;
		}
		else if (s[i] == ' ')
		{
			i++;
			continue ;
		}
		i++;
	}
	if (count == 0)
		errors("Error\nNot enough/wrong elements/wrong starting position in map!\n");
	return ;
}

static int check_str_content(char *content, t_all *all, t_list *tmp)
{
	//int	i;

	//i = -1;
	if (!check_only_spaces(content)) //if str contains only spaces we skip it
		return (1);
	else if (is_map(tmp)) //if we find map then we stop processing in that func, process map and return filled structs and map
	{
		if (!check_if_all_elems_filled(all))
			errors("Error\nNot enough elements!\n");
		create_map(tmp, ft_lstsize(tmp), all); //we fill map
		return (0);
	}
	process_elements(content, all);
	return (1);
}

void	check_list_content(t_list **head, t_all *all)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (!check_str_content(tmp->content, all, tmp))
			break ;
		tmp = tmp->next;
	}
}
