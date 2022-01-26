#include "../cub.h"

static void	valid_elems(char *s, t_all *all, int i)
{
	if (s[i] == 'C')
	{
		if (all->colors->ceiling_color)
			errors("Error\nToo many ceiling colors!\n");
		all->colors->ceiling_color = s;
	}
	else if (s[i] == 'F')
	{
		if (all->colors->floor_color)
			errors("Error\nToo many floor colors!\n");
		all->colors->floor_color = s;
	}
	else if (s[i] == 'R')
	{
		if (all->resol->resolution)
			errors("Error\nToo many resolution values!\n");
		all->resol->resolution = s;
	}
	else
		errors("Error\nNot enough or wrong elements!\n");
}

void	valid_text(char *s, t_all *all, int i)
{
	if (s[i] == 'N' && s[i + 1] == 'O')
	{
		if (all->text->path_north)
			errors("Error\nToo many same textures paths!\n");
		all->text->path_north = s;
	}
	else if (s[i] == 'W' && s[i + 1] == 'E')
	{
		if (all->text->path_west)
			errors("Error\nToo many same textures paths!\n");
		all->text->path_west = s;
	}
	else if (s[i] == 'S' && s[i + 1] == 'O')
	{
		if (all->text->path_south)
			errors("Error\nToo many same textures paths!\n");
		all->text->path_south = s;
	}
	else if (s[i] == 'E' && s[i + 1] == 'A')
	{
		if (all->text->path_east)
			errors("Error\nToo many same textures paths!\n");
		all->text->path_east = s;
	}
	else
		valid_elems(s, all, i);
}
