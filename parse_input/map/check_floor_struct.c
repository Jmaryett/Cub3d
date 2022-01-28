#include "../../cub.h"

static void	fill_floor_struct(char *tmp, t_all *all)
{
	int	i;

	i = skip_space(tmp, ' ');
	all->colors->floor_r = ft_atoi_m(&tmp[i]);
	i = i + ft_strlen_m(&tmp[i], ',') + 1;
	all->colors->floor_g = ft_atoi_m(&tmp[i]);
	i = i + ft_strlen_m(&tmp[i], ',') + 1;
	all->colors->floor_b = ft_atoi_m(&tmp[i]);
}

static char	*check_if_floor_is_digit(char *str, int i)
{
	//char	**rgb;
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
	// printf("tmp = %s\n", tmp);
	// rgb = ft_calloc(BUF_SIZE, sizeof(char *));
	// if (!rgb)
	// 	errors("Error\nTroubles with malloc in check_if_floor_is_digit\n");
	// rgb = ft_split(tmp, ',');
	// free(tmp);
	// is_valid_symbols(rgb);
	return(tmp);
}

void	check_floor_struct(char *colors, t_all *all)
{
	int	i;
	char	*tmp;

	i = 0;
	while(colors[i] == ' ')
		i++;
	if (colors[i] != 'F') //or &&?
		errors("Error\nWrong or no identifier for the floor!\n");
	else
	{
		i += 1;
		if (colors[i] != ' ')
			errors("Error\nF should be accompanied by at least one space!\n");
		else
		{
			tmp = check_if_floor_is_digit(colors, i);
			fill_floor_struct(tmp, all);
			free (tmp);
			return ;
		}
	}
}
