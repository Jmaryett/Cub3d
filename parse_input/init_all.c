#include "../cub.h"

static void	init_text(t_text_path *text)
{
	text->path_east = NULL;
	text->path_west = NULL;
	text->path_north = NULL;
	text->path_south = NULL;
}

static void	init_colors(t_ceiling *ceiling, t_floor *floor)
{
	ceiling->ceiling_b = -1;
	ceiling->ceiling_r = -1;
	ceiling->ceiling_g = -1;
	ceiling->ceiling_color = NULL;
	floor->floor_b = -1;
	floor->floor_r = -1;
	floor->floor_g = -1;
	floor->floor_color = NULL;
}

// static void	init_resolution(t_resol *resol)
// {
// 	resol->resolution = NULL;
// 	resol->resol_x = -1;
// 	resol->resol_y = -1;
// }

void	init_all(t_all *all)
{
	init_text(&all->text);
	init_colors(&all->ceiling, &all->floor);
	//init_resolution(&all->resol);
}
