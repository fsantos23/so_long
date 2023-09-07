/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:58:50 by fsantos2          #+#    #+#             */
/*   Updated: 2023/09/07 15:05:47 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	rectangle(t_all *all)
{
	char	**map;
	int		x;
	int		y;

	y = 0;
	map = all->map.map;
	if (all->window.coor.x == all->window.coor.y)
		return (-1);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (check_letters(map[y][x]) == -1)
				return (-1);
			x++;
		}
		if ((all->window.coor.x + 1) != x && (y + 1) != all->lines)
			return (-1);
		y++;
	}
	return (0);
}

int	check_map(t_all *all)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	map = all->map.map;
	x = 0;
	while (x < all->window.coor.x)
	{
		if (map[0][x] != '1' || map[all->lines - 1][x] != '1')
			return (-1);
		x++;
	}
	while (y < all->window.coor.y)
	{
		if (map[y][0] != '1' || map[y][all->window.coor.x - 1] != '1')
			return (-1);
		y++;
	}
	return (0);
}

int	check_letters(char letter)
{
	if (letter == '1' || letter == '0' || letter == 'C' || letter == 'E' \
		|| letter == 'P' || letter == '\n')
		return (0);
	return (-1);
}
