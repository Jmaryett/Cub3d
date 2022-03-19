#include "cub.h"

void	check_file_name(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'b')
		errors("Error\nWrong file extension\n");
	else if (filename[len - 2] != 'u')
		errors("Error\nWrong file extension\n");
	else if (filename[len - 3] != 'c')
		errors("Error\nWrong file extension\n");
	else if (filename[len - 4] != '.')
		errors("Error\nWrong file extension\n");
	return ;
}

int	check_folder_valid_file(char *av)
{
	int	fd;

	fd = open(av, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		errors("Error\nFile mustn't be a folder!\n");
	}
	close(fd);
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		errors("Error\nTroubles while opening file: wrong fd\n");
	}
	return (fd);
}

void	check_input(char *av, t_all *all)
{
	int		fd;
	char	*line;
	t_list	*head;
	//t_list *tmp;

	line = NULL;
	head = NULL;
	check_file_name(av);
	fd = check_folder_valid_file(av);
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew((void *)line));
	ft_lstadd_back(&head, ft_lstnew((void *)line));
	check_list_content(&head, all);
	// while(head)
	// {
	// 	tmp = head->next;
	// 	if (head->content)
	// 		free(head->content);
	// 	free(head);
	// 	head = tmp;
	// }
	// // while (1);
	ft_lstclear(&head, free);
	//check_xpm();
}
