/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:49:52 by fsantos2          #+#    #+#             */
/*   Updated: 2023/09/07 12:15:09 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	flood_fill(int x, int y, char **map, int *counter)
{
	if (map[y][x] == 'E' || map[y][x] == 'C')
		*counter += 1;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	map[y][x] = 'F';
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'F')
		flood_fill(x + 1, y, map, counter);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'F')
		flood_fill(x - 1, y, map, counter);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'F')
		flood_fill(x, y + 1, map, counter);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'F')
		flood_fill(x, y - 1, map, counter);
}

int	fill(t_all *all)
{
	int		y;
	int		counter;
	char	**tmp_map;

	tmp_map = (char **)malloc(sizeof(char *) * (all->window.coor.y + 1));
	counter = 0;
	y = 0;
	while (all->map.map[y])
	{
		tmp_map[y] = ft_strdup(all->map.map[y]);
		y++;
	}
	tmp_map[y] = NULL;
	flood_fill(all->sprite.player.x, all->sprite.player.y, tmp_map, &counter);
	if (counter != all->count.count_all)
	{
		free_array(tmp_map);
		return (-1);
	}
	free_array(tmp_map);
	return (0);
}

void	counter_collectibles(t_all *all)
{
	char	**map;
	int		x;
	int		y;

	y = 0;
	map = all->map.map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				all->sprite.player.x = x;
				all->sprite.player.y = y;
			}
			if (map[y][x] == 'C' || map[y][x] == 'E')
				all->count.count_all++;
			x++;
		}
		y++;
	}
}
