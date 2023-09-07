/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:52:27 by fsantos2          #+#    #+#             */
/*   Updated: 2023/09/07 12:15:14 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_player(int keycode, t_all *all, int *x, int *y)
{
	char	**map;

	map = all->map.map;
	map[*y][*x] = '0';
	if (move_player(keycode, all, x, y) == 0)
		return (0);
	set_background("./sprites/background.xpm", all);
	check_layout(all);
	return (0);
}

int	move_player(int keycode, t_all *all, int *x, int *y)
{
	if (keycode == W)
	{
		if (move_up(all, x, y) == 0)
			return (0);
	}
	else if (keycode == A)
	{
		if (move_left(all, x, y) == 0)
			return (0);
	}
	else if (keycode == S)
	{
		if (move_down(all, x, y) == 0)
			return (0);
	}
	else if (keycode == D)
	{
		if (move_right(all, x, y) == 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

int	check_wall(t_all *all, char map)
{
	if (map == '1')
		return (-1);
	else if (map == 'E')
	{
		if (check_exit(all, map) == 0)
			return (-1);
	}
	return (0);
}
