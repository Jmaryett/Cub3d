#include "get_next_line.h"

int	main(void)
{
	int		ret_val;
	char	*line;
	int		fd;

	fd = open("multiple_nlx5", O_RDONLY);
	if (fd <0)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		//free(line);
	}
	printf("%s\n", line);
		free(line);
	return (0);
	//while ()
}