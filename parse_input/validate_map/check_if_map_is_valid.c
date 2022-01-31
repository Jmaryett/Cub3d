#include "../../cub.h"

static void	add_check_map_char_empty_lines(char **map, int i, int j)
{
	if (!check_only_spaces(map[i]))
		errors("Error\nEmpty lines in map\n");
	else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
		&& map[i][j] != 'S' && map[i][j] != 'W' && map[i][j] != 'E'
		&& map[i][j] != ' ')
		errors("Error\nWrong symbols in map!\n");
}

void	check_map_char_empty_lines(char **map, int i, int j, t_plr *player)
{
	int	pos_flag;

	pos_flag = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			add_check_map_char_empty_lines(map, i, j);
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (pos_flag != 0)
					errors("Error\nToo many player's position in map!\n");
				pos_flag = 1;
				player->x = j;
				player->y = i;
			}
			j++;
		}
		i++;
	}
}

void	check_if_map_is_valid(char **map, t_plr *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_map_char_empty_lines(map, i, j, player);
	check_walls(map, i, j);
}