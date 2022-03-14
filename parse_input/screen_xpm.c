#include "../../cub.h"

static void	set_img_struct(t_all *all, t_image *texture, char *path)
{
	int	sz[2]; //for image size

	if (!texture)
		errors("Error\nCan't allocate memory init_sprites()\n");
	texture->img = mlx_xpm_file_to_image(all->win.mlx, path, &sz[0], &sz[1]);
	if (!texture->img)
		errors("Error\nCan't read xpm file!\n");
	if (sz[0] != SPRITE_SZ || sz[0] != sz[1])
		errors("Error\nIncorrect xpm size!\n");
	texture->addr = mlx_get_data_addr(texture->img, &texture->b_p_p, &texture->line_len, &texture->endian);
	texture->b_p_p = texture->b_p_p / 8;
}

void	init_sprites(t_sprites *sprites, t_all *all)
{
	sprites->img_north = malloc(sizeof(t_image));
	set_img_struct(all, sprites->img_north, all->text.path_north);
	sprites->img_south = malloc(sizeof(t_image));
	set_img_struct(all, sprites->img_south, all->text.path_south);
	sprites->img_east = malloc(sizeof(t_image));
	set_img_struct(all, sprites->img_east, all->text.path_east);
	sprites->img_west = malloc(sizeof(t_image));
	set_img_struct(all, sprites->img_west, all->text.path_west);
}
