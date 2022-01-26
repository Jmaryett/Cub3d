#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	if (*str == '\0' || !str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)ch)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
