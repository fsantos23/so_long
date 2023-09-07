/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:54:43 by fsantos2          #+#    #+#             */
/*   Updated: 2023/09/07 12:15:17 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	move_up(t_all *all, int *x, int *y)
{
	int	i;
	int	j;

	i = *x;
	j = *y;
	if (check_wall(all, all->map.map[j - 1][i]) == -1)
		return (0);
	*y -= 1;
	all->moves.moves++;
	all->map.map[*y][*x] = 'P';
	ft_printf("move = %d\n", all->moves.moves);
	return (1);
}

int	move_left(t_all *all, int *x, int *y)
{
	int	i;
	int	j;

	i = *x;
	j = *y;
	if (check_wall(all, all->map.map[j][i - 1]) == -1)
		return (0);
	*x -= 1;
	all->moves.moves++;
	all->map.map[*y][*x] = 'P';
	ft_printf("move = %d\n", all->moves.moves);
	return (1);
}

int	move_down(t_all *all, int *x, int *y)
{
	int	i;
	int	j;

	i = *x;
	j = *y;
	if (check_wall(all, all->map.map[j + 1][i]) == -1)
		return (0);
	*y += 1;
	all->moves.moves++;
	all->map.map[*y][*x] = 'P';
	ft_printf("move = %d\n", all->moves.moves);
	return (1);
}

int	move_right(t_all *all, int *x, int *y)
{
	int	i;
	int	j;

	i = *x;
	j = *y;
	if (check_wall(all, all->map.map[j][i + 1]) == -1)
		return (0);
	*x += 1;
	all->moves.moves++;
	all->map.map[*y][*x] = 'P';
	ft_printf("move = %d\n", all->moves.moves);
	return (1);
}
