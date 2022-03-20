/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:30:07 by jmaryett          #+#    #+#             */
/*   Updated: 2022/03/20 15:30:08 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//t_list *tmp;
// while(head)
// {
// 	tmp = head->next;
// 	if (head->content)
// 		free(head->content);
// 	free(head);
// 	head = tmp;
// }
//check_xpm(); in the end
void	check_input(char *av, t_all *all)
{
	int		fd;
	char	*line;
	t_list	*head;

	line = NULL;
	head = NULL;
	check_file_name(av);
	fd = check_folder_valid_file(av);
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew((void *)line));
	ft_lstadd_back(&head, ft_lstnew((void *)line));
	check_list_content(&head, all);
	ft_lstclear(&head, free);
}
