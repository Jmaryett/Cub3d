#include "cub.h"

void	start_mlx(t_all *all)
{
	all->win.mlx = mlx_init();
	//init_sprites(&all->sprites, all);
	//if we want a screen being dynamically allocated, then we don't need func below, Artem should
	//find size of the textures when finding the ray or so
	all->win.win = mlx_new_window(all->win.mlx, RES_X * SPRITE_SZ, RES_Y * SPRITE_SZ, "cub3D");
	//here is the game process should be
	//mlx_hook(all->win.win, 2, 1, 1L << 0, key_pressed, all);
	//mlx_hook(all->win.win, 2, 1, 1L << 1, key_released, all);
	//mlx_hook(all->win.win, 17, 1, 1L << 2, esc, all); // funcs for pressing, releasing keys
	mlx_loop(all->win.mlx);
}

int	main(int ac, char **av)
{
	t_all		all;

	if (ac != 2)
		errors("Error\nWrong number of args!\n");
	init_all(&all);
	check_input(av[1], &all);
	//start_mlx(&all);
	exit(0);
}
