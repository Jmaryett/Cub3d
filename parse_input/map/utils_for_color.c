#include "../../cub.h"

size_t	ft_strlen_m(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	if (!c)
	{
		while (str[i])
			i++;
	}
	else
	{
		while (str[i] && str[i] != (unsigned char)c)
			i++;
		if (!str[i])
			i = 0;
	}
	return (i);
}

int	skip_space(char *str, unsigned char sym)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] == sym)
		i++;
	//while (str[i] && str[i] != sym)
	//	i++;
	//while (str[i] && str[i] == sym)
	//	i++;
	return (i);
}

int	ft_atoi_m(const char *str)
{
	int					negative;
	unsigned long long	res;

	negative = 1;
	res = 0;
	while (*str && (*str == 32 || (*str > 8 && *str < 14)))
		str++;
	if (*str == '-')
		errors("Error\nIncorrect color format(atoi_m 1)");
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9' && res <= 255)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if ((res > 255 && negative == 1) || (*str != ',' && *str != 0))
		errors("Error\nIncorrect color format(atoi_m 2)");
	return ((int)res * negative);
}