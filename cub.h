#ifndef CUB_H

# define CUB_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <math.h>
#include <limits.h>
//#include "mlx/mlx.h"
//#include "/usr/include/X11"
#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"

# define SCALE 16 //conditionally our square size in the map
# define BUF_SIZE 32
# define RES_X 1280
# define RES_Y 720
# define SPRITE_SZ 64

//struct for a window

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
}			t_win;

//for a point or aim??

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

//for a player and ray

typedef struct s_plr
{
	float	x;
	float	y;
	char	dir;
	float	start;
	float	end;
}			t_plr;

//struct for xpm to img for each texture

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		b_p_p;
	int		line_len;
	int		endian;
}			t_image;

//each struct will have it's info with xpm, addr, etc. 
//struct for wall textures, not for bonuses

typedef struct s_sprites
{
	t_image	*img_north;
	t_image	*img_south;
	t_image	*img_east;
	t_image	*img_west;
}				t_sprites;

//floor and ceiling colors structure, chars needed by jmaryett

typedef struct s_floor
{
	char	*floor_color;
	int		floor_r;
	int		floor_g;
	int		floor_b;
}				t_floor;

typedef struct s_ceiling
{
	char	*ceiling_color;
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
}			t_ceiling;

//structure for texture paths

typedef struct s_text_path
{
	char	*path_north;
	char	*path_south;
	char	*path_east;
	char	*path_west;
}			t_text_path;

typedef struct s_all
{
	t_win		win;
	t_plr		plr;
	t_text_path	text;
	t_floor		floor;
	t_ceiling	ceiling;
	t_sprites	sprites; //for working with pixels and mlx
	char		**map;
}			t_all;

//util func

void	errors(char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		check_only_spaces(char *s);
int		ft_atoi_m(const char *str);
int		skip_space(char *str, unsigned char sym);
size_t	ft_strlen_m(const char *str, int c);
int		skip_whitespace(char *str);
void	clean_struct_all(t_all *all);


//parse funcs

void	check_input(char *av, t_all *all);
void	check_list_content(t_list **head, t_all *all);
void	init_all(t_all *all);
void	valid_text(char *s, t_all *all, int i);

//validating input for each element including map

void	create_map(t_list *map_head, int size, t_all *all);
int		check_if_all_elems_filled(t_all *all);

void	check_text_struct(t_all *all);
void	check_ceiling_struct(char *colors, t_all *all);
void	check_floor_struct(char *colors, t_all *all);
void	check_ceiling_format(char *str, t_ceiling *ceiling);
void	check_floor_format(char *str, t_floor *floor);
int		move_i(char *s, int i);
int		skip_space_in_s(char *s, int i);

void	check_if_map_is_valid(char **map, t_plr *player);
void	check_walls(char **map, int i, int j);
void	check_how_map_filled(char **map, int i, int j);

void	fix_text_path(t_text_path *text);

void	init_sprites(t_sprites *sprites, t_all *all);

//end of parse


#endif