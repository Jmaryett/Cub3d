#include "../../cub.h"

static int check_spaces_in_map(char **map, int i, int j)
{
	if (j != 0 && map[i][j - 1] != '1')
		errors("Error\nWrong map format check_spaces_in_map_1\n"); // if before space was not 1
	while (map[i][j] == ' ')
	{
		if (i != 0)//map[i - 1]
			if (map[i - 1][j] != ' ' && map[i - 1][j] != '1' 
				&& (map[i - 1][j - 1] == '0' || map[i - 1][j + 1] == '0')) // if above and aside isn't 1 or space
				errors("Error\nWrong map format check_spaces_in_map_2\n");
		if (map[i + 1] && map[i + 1][0] != '\0')
			if (map[i + 1][j - 1] == '0' || map[i + 1][j + 1] == '0')
				errors("Error\nWrong map format check_spaces_in_map_3\n");
		j++;
	}
	if (map[i][j] != '1')
		errors("Error\nWrong map format check_spaces_in_map_3\n");
	return (j);
}

static int check_zero_in_map(char **map, int i, int j)
{
	if (j != 0 && map[i][j - 1] != '1')
		errors("Error\nWrong map format check_zero_in_map_1\n"); // if before zero was not 1
	while (map[i][j] == '0')
	{
		if (map[i - 1][j] != '1' && map[i - 1][j] != '0') // if above isn't 1 or 0
			errors("Error\nWrong map format check_zero_in_map_2\n");
		else if (map[i + 1][j] != '1' && map[i + 1][j] != '0') // if below isn't 1 or 0
			errors("Error\nWrong map format check_zero_in_map_4\n");
		else if ((map[i + 1][j - 1] != '1' && map[i + 1][j - 1] != '0')
			|| (map[i - 1][j - 1] != '1' && map[i - 1][j - 1] != '0')
			|| (map[i + 1][j + 1] != '1' && map[i + 1][j + 1] != '0')
			|| (map[i - 1][j + 1] != '1' && map[i - 1][j + 1] != '0')) //if on diagonal above and below zero isn't 1 or 0
				errors("Error\nWrong map format check_zero_in_map_5\n");
		j++;
	}
	if (map[i][j] != '1')
		errors("Error\nWrong map format check_spaces_in_map_6\n"); // if after 0 isn't 1??
	return (j);
}

void check_how_map_filled(char **map, int i, int j)
{
	while (map[i])
	{
		// printf ("str[%d] start = %c\n", i, map[i][0]);
		if (map[i + 1] == NULL && map[i][0] == '\0') // check if last line is empty
			break;
		if (map[i][0] != '1' && map[i][0] != ' ') // if first symbol of the line is not 1 or space
			errors("Error\nWrong map format check_how_map_filled_1(str start)\n");
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				j = check_spaces_in_map(map, i, j);
			if (map[i][j] == '0')
				j = check_zero_in_map(map, i, j);
			j++;
		}
		// printf ("str[%d] end(-1) = %c\n", i, map[i][j - 1]);
		if (map[i][j - 1] != '1')
			errors("Error\nWrong map format check_how_map_filled_2(str end)\n"); // i check if line ends with 1
		i++;
	}
}
