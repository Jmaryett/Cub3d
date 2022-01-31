#include "../../cub.h"

static int fill_rgb(char *str, int flag, t_floor *floor, int i)
{
	if (floor->floor_r == -1)
	{
		floor->floor_r = ft_atoi_m(&str[i]);
		flag++;
	}
	else if (floor->floor_g == -1)
	{
		floor->floor_g = ft_atoi_m(&str[i]);
		flag++;
	}
	else if (floor->floor_b == -1)
	{
		floor->floor_b = ft_atoi_m(&str[i]);
		flag++;
	}
	return (flag);
}

void check_floor_format(char *str, t_floor *floor)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		i = skip_space_in_s(str, i);
		if (!ft_isdigit(str[i]))
			errors("Error\nWrong color format!\n");
		flag = fill_rgb(str, flag, floor, i);
		i = move_i(str, i);
		i = skip_space_in_s(str, i);
		if (str[i] == ',' && flag != 3 && str[i + 1] != '\0')
		{
			i++;
			continue;
		}
		else if (flag == 3 && str[i] == '\0')
			break;
		else
			errors("Error\nWrong color format check_floor_format\n");
	}
}
