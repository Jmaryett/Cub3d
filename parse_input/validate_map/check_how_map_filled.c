#include "../../cub.h"

static int	check_spaces_in_map(char **map, int i, int j)
{
	if (map[i][j - 1] != '1')
		errors("Error\nWrong map format check_spaces_in_map_1\n"); //if before space was not 1
	while(map[i][j] == ' ')
	{
		if (map[i - 1])
			if (map[i - 1][j] != ' ' && map[i - 1][j] != '1') //if above isn't 1 or space
				errors("Error\nWrong map format check_spaces_in_map_2\n");
		// if (map[i + 1])
		// 	if (map[i + 1][j] != ' ' && map[i + 1][j] != '1')
		// 		errors("Error\nWrong map format check_spaces_in_map_3\n"); //maybe i don't need to check last line
		j++;
	}
	if (map[i][j] != '1')
		errors("Error\nWrong map format check_spaces_in_map_3\n");
	return (j);
}

void	check_how_map_filled(char **map, int i, int j)
{
	while (map[i])
	{
		printf ("str[%d] start = %c\n", i, map[i][0]);
		if (map[i + 1] == NULL && map[i][0] == '\0')
			break ;
		if (map[i][0] != '1' && map[i][0] != ' ') //if first symbol of the line is not 1 or space
			errors("Error\nWrong map format check_how_map_filled_1(str start)\n");
		j = 0;
		while(map[i][j])
		{	
			if (map[i][j] == ' ')
				j = check_spaces_in_map(map, i, j);
			j++;
		}
		printf ("str[%d] end(-1) = %c\n", i, map[i][j - 1]);
		if (map[i][j - 1] != '1')
			errors("Error\nWrong map format check_how_map_filled_2(str end)\n");
		i++;
	}
}