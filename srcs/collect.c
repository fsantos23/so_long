/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:29:41 by fsantos2          #+#    #+#             */
/*   Updated: 2023/09/07 12:15:00 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_collect(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

void	free_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_exit(t_all *all, char map)
{
	if (check_collect(all->map.map) == 0 && map == 'E')
	{
		free_sprites_and_shit(all);
		mlx_destroy_window(all->window.mlx_ptr, all->window.mlx_win);
		mlx_destroy_display(all->window.mlx_ptr);
		free_array(all->map.map);
		free(all->window.mlx_ptr);
		free(all);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
