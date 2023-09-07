/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:34:35 by fsantos2          #+#    #+#             */
/*   Updated: 2023/09/07 14:29:07 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	map_size(t_all *all, int fd)
{
	char	*line;
	char	**map;
	int		lines;
	int		j;

	line = NULL;
	lines = num_lines(fd);
	map = malloc((lines + 1) * sizeof(char *));
	close(fd);
	fd = open(all->fd.fd_file, O_RDONLY);
	j = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[j] = line;
		j++;
	}
	map[j] = NULL;
	all->window.coor.x = ft_strlen(map[j - 1]);
	all->window.coor.y = j;
	all->map.map = map;
	all->lines = j;
}

void	check_layout(t_all *all)
{
	int		x;
	int		y;
	char	**map;

	map = all->map.map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_check_sprite(map[y][x], all, x, y);
			x++;
		}
		y++;
	}
}

int	num_lines(int fd)
{
	char	*line;
	int		j;

	line = NULL;
	j = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		j++;
	}
	return (j);
}
