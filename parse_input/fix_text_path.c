#include "../cub.h"

static char	*fix_east(char *east)
{
	char	*new_east;
	char	*tmp;
	int	i;
	int	len;

	i = skip_whitespace(east);
	while(east[i])
	{
		if(east[i] == 'E')
		{
			i += 2;
			break;
		}
		i++;
	}
	len = i;
	while(east[len])
		len++;
	tmp = ft_substr(east, i, len);
	new_east = ft_strtrim(tmp, " 	");
	free(east);
	free(tmp);
	return(new_east);
}

static char	*fix_west(char *west)
{
	char	*new_west;
	char	*tmp;
	int	i;
	int	len;

	i = skip_whitespace(west);
	while(west[i])
	{
		if(west[i] == 'W')
		{
			i += 2;
			break;
		}
		i++;
	}
	len = i;
	while(west[len])
		len++;
	tmp = ft_substr(west, i, len);
	new_west = ft_strtrim(tmp, " 	");
	free(west);
	free(tmp);
	return(new_west);
}


static char	*fix_south(char *south)
{
	char	*new_south;
	char	*tmp;
	int	i;
	int	len;

	i = skip_whitespace(south);
	while(south[i])
	{
		if(south[i] == 'S')
		{
			i += 2;
			break;
		}
		i++;
	}
	len = i;
	while(south[len])
		len++;
	tmp = ft_substr(south, i, len);
	new_south = ft_strtrim(tmp, " 	");
	free(south);
	free(tmp);
	return(new_south);
}

static char	*fix_north(char *north)
{
	char	*new_north;
	char	*tmp;
	int	i;
	int	len;

	i = skip_whitespace(north);
	while(north[i])
	{
		if(north[i] == 'N')
		{
			i += 2;
			break;
		}
		i++;
	}
	len = i;
	while(north[len])
		len++;
	tmp = ft_substr(north, i, len);
	new_north = ft_strtrim(tmp, " 	");
	free(north);
	free(tmp);
	return(new_north);
}


void	fix_text_path(t_text_path *text)
{
	text->path_east = fix_east(text->path_east);
	text->path_west = fix_west(text->path_west);
	text->path_south = fix_south(text->path_south);
	text->path_north = fix_north(text->path_north);
}