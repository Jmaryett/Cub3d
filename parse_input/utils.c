#include "../cub.h"

int	check_only_spaces(char *s)
{
	int	i;
	int	not_empty_s;

	if (!s)
		return (0);
	not_empty_s = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != ' ')
			not_empty_s = 1;
	}
	return (not_empty_s);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	index;
	int				comp_value;

	index = 0;
	if (!s1 || !s2)
		return (s1 == s2);
	while (s1[index] || s2[index])
	{
		comp_value = (unsigned char)s1[index] - (unsigned char)s2[index];
		if (comp_value)
			return (comp_value);
		index++;
	}
	return (0);
}
