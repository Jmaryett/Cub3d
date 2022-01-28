#include "../../cub.h"

//here i check if there are correct number of symbols and if they are digits
// void	is_valid_symbols(char **rgb)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while(rgb[i])
// 		{ printf("rgb = %s\n", rgb[i]); i++;}
// 	if (i != 3)
// 		errors("Error\nWrong number in floor or ceiling elements!\n");
// 	i = 0;
// 	while(rgb[i])
// 	{
// 		j = 0;
// 		// while(rgb[i][j] == ' ')
// 		// 	j++;
// 		// if (!ft_isdigit(rgb[i][j]))
// 		// 	errors("Error\nF and C should contain only positive digits!\n");
// 		// else
// 		// {
// 			//j++;
// 			while(rgb[i][j])
// 			{
// 				while(rgb[i][j] == ' ')
// 					j++;
// 				if (!ft_isdigit(rgb[i][j]))
// 					errors("Error\nF and C should contain only positive digits!\n");
// 				else if (rgb[i][j + 1] == ' ')
// 				{
// 					while(rgb[i][j++])
// 						if (rgb[i][j] != ' ' && rgb[i][j] != '\0')
// 							errors("Error\nDigits should be separated by commas and be positive digits\n");
// 				}
// 				else
// 					j++;
// 			}
// 		//}
// 		i++;
// 	}
// }


static void	fill_ceiling_struct(char *tmp, t_all *all)
{
	int	i;

	i = skip_space(tmp, ' ');
	all->colors->ceiling_r = ft_atoi(&tmp[i]);
	i = i + ft_strlen_m(&tmp[i], ',') + 1;
	all->colors->ceiling_g = ft_atoi(&tmp[i]);
	i = i + ft_strlen_m(&tmp[i], ',') + 1;
	all->colors->ceiling_b = ft_atoi(&tmp[i]);
}

static char	*check_if_ceiling_is_digit(char *str, int i)
{
	//char	**rgb;
	char	*tmp;
	int		len;

	if (!check_only_spaces(str))
		errors("Error\nNo C colors!\n");
	while (str[i] == ' ')
		i++;
	if (!ft_isdigit(str[i]))
		errors("Error\nAfter identifier should be a positive digit!\n");
	len = i;
	while(str[len])
		len++;
	tmp = ft_substr(str, i, len); //i cut the identifier first and left only what is after
	// rgb = ft_calloc(BUF_SIZE, sizeof(char *));
	// if (!rgb)
	// 	errors("Error\nTroubles with malloc in check_if_ceiling_is_digit\n");
	// rgb = ft_split(tmp, ',');
	// if (!rgb)
	// 	return (NULL);
	// free(tmp);
	// is_valid_symbols(rgb);
	return(tmp);
}

void	check_ceiling_struct(char *colors, t_all *all)
{
	int	i;
	char	*tmp;

	i = 0;
	while(colors[i] == ' ')
		i++;
	if (colors[i] != 'C') //or &&?
		errors("Error\nWrong or no identifier for the ceiling!\n");
	else
	{
		i += 1;
		if (colors[i] != ' ')
			errors("Error\nC should be accompanied by at least one space!\n");
		else
		{
			tmp = check_if_ceiling_is_digit(colors, i);
			fill_ceiling_struct(tmp, all);
			free(tmp);
			return ;
		}
	}
}
