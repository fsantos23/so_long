/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:35:20 by fsantos2          #+#    #+#             */
/*   Updated: 2023/09/07 15:06:02 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int argc, char **argv)
{
	t_all	*all;
	int		fd;

	if (argc == 2)
	{
		if (ft_strlen(ft_strchr(argv[1], '.')) != 4 \
			|| ft_strncmp(ft_strchr(argv[1], '.'), ".ber", 4))
			return (ft_printf("Extension not correct\n"));
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			close(fd);
			return (ft_printf("File does not exist\n"));
		}
		all = ft_calloc(1, sizeof(t_all));
		all->fd.fd_file = argv[1];
		start_game(all, fd);
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
}
