#include "../cub.h"

static void	init_text(t_text_path *text)
{
	text->path_east = NULL;
	text->path_west = NULL;
	text->path_north = NULL;
	text->path_south = NULL;
}

static void	init_colors(t_colors *colors)
{
	colors->ceiling_b = -1;
	colors->ceiling_r = -1;
	colors->ceiling_g = -1;
	colors->ceiling_color = NULL;
	colors->floor_b = -1;
	colors->floor_r = -1;
	colors->floor_g = -1;
	colors->floor_color = NULL;
}

static void	init_resolution(t_resol *resol)
{
	resol->resolution = NULL;
	resol->resol_x = -1;
	resol->resol_y = -1;
}

void	init_all(t_all *all, t_text_path *text, t_colors *colors, t_resol *resol)
{
	init_text(text);
	init_colors(colors);
	init_resolution(resol);
	all->colors = colors;
	all->resol = resol;
	all->text = text;
}
