/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:48:07 by fsantos2          #+#    #+#             */
/*   Updated: 2023/09/07 12:15:03 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	exit_window(int keycode, t_all *all)
{
	if (keycode == ESCAPE)
	{
		free_sprites_and_shit(all);
		mlx_destroy_window(all->window.mlx_ptr, all->window.mlx_win);
		mlx_destroy_display(all->window.mlx_ptr);
		free_array(all->map.map);
		free(all->window.mlx_ptr);
		free(all);
		exit(EXIT_SUCCESS);
	}
	check_player(keycode, all, &all->sprite.player.x, &all->sprite.player.y);
	return (0);
}

int	exit_cross(t_all *all)
{
	if (all->window.mlx_win)
	{
		free_sprites_and_shit(all);
		mlx_destroy_window(all->window.mlx_ptr, all->window.mlx_win);
		mlx_destroy_display(all->window.mlx_ptr);
		free_array(all->map.map);
		free(all->window.mlx_ptr);
		free(all);
		exit(EXIT_SUCCESS);
	}
	exit(0);
}

void	ft_exit(t_all *all)
{
	mlx_hook(all->window.mlx_win, 02, 1L << 0, exit_window, all);
	mlx_hook(all->window.mlx_win, DestroyNotify, KeyPressMask, exit_cross, all);
}
