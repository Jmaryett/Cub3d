#include "../../cub.h"

void	check_walls(char **map, int i, int j)
{
	int	len;

	len = 0;
	(void)i;
	while (map[len])
		len++;
	while(map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
			errors("Error\nWrong symbols in the first line check_walls_1\n");
		j++;
	}
	j = 0;
	printf("map[len] = %s, map[len - 1] = %s\n", map[len], map[len-1]);
	if (map[len - 1][0] == '\0')
		return ;
	else if (!check_only_spaces(map[len - 1]))
		errors("Error\nOnly spaces in the last line of the map check_walls_2\n");
	while(map[len - 1][j])
	{
		if (map[len - 1][j] != '1' && map[len - 1][j] != ' ')
			errors("Error\nWrong symbols in the last line check_walls_3\n");
		j++;
	}
}
