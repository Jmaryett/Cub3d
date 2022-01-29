#include "../../cub.h"

static char	*cut_ceiling_identifier(char *str, int i)
{
	char	*tmp;
	int		len;

	if (!check_only_spaces(str))
		errors("Error\nNo C colors!\n");
	while (str[i] == ' ')
		i++;
	if (!ft_isdigit(str[i]))
		errors("Error\nAfter C should be a positive digit!\n");
	len = i;
	while(str[len])
		len++;
	tmp = ft_substr(str, i, len); //i cut the identifier first and left only what is after
	return(tmp);
}

void	check_ceiling_struct(char *colors, t_all *all)
{
	int	i;
	char	*tmp;

	i = skip_space(colors, ' ');
	if (colors[i] != 'C')
		errors("Error\nWrong or no identifier for the ceiling!\n");
	else
	{
		i += 1;
		if (colors[i] != ' ')
			errors("Error\nC should be accompanied by at least one space!\n");
		else
		{
			tmp = cut_ceiling_identifier(colors, i);
			check_ceiling_format(tmp, &all->ceiling);
			free(tmp);
			return ;
		}
	}
}
