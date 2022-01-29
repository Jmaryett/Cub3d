#include "../../cub.h"

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
	while(str[len])
		len++;
	tmp = ft_substr(str, i, len); //i cut the identifier first and left only what is after
	return(tmp);
}

void	check_floor_struct(char *colors, t_all *all)
{
	int	i;
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
