/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:00:27 by fsantos2          #+#    #+#             */
/*   Updated: 2023/09/07 13:13:13 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_check_sprite(char str, t_all *all, int x, int y)
{
	if (str == '1')
		mlx_put_image_to_window(all->window.mlx_ptr, all->window.mlx_win, \
				all->sprite.wall, SIZE * x, SIZE * y);
	else if (str == 'P')
	{
		mlx_put_image_to_window(all->window.mlx_ptr, all->window.mlx_win, \
				all->sprite.player.player, SIZE * x, SIZE * y);
	}
	else if (str == 'C')
	{
		mlx_put_image_to_window(all->window.mlx_ptr, all->window.mlx_win, \
				all->sprite.beer, SIZE * x, SIZE * y);
		all->count.count_coll++;
	}
	else if (str == 'E')
	{
		mlx_put_image_to_window(all->window.mlx_ptr, all->window.mlx_win, \
				all->sprite.exit, SIZE * x, SIZE * y);
		all->count.count_exit++;
	}
}

void	ft_xpm_to_image(t_all *all)
{
	all->sprite.water1 = mlx_xpm_file_to_image(all->window.mlx_ptr,
			"./sprites/Water1.xpm", &all->image.w, &all->image.h);
	all->sprite.wall = mlx_xpm_file_to_image(all->window.mlx_ptr,
			"./sprites/wall.xpm", &all->image.w, &all->image.h);
	all->sprite.tree0 = mlx_xpm_file_to_image(all->window.mlx_ptr,
			"./sprites/Tree-0.xpm", &all->image.w, &all->image.h);
	all->sprite.tree1 = mlx_xpm_file_to_image(all->window.mlx_ptr,
			"./sprites/Tree-1.xpm", &all->image.w, &all->image.h);
	all->sprite.rock0 = mlx_xpm_file_to_image(all->window.mlx_ptr,
			"./sprites/Rock-0.xpm", &all->image.w, &all->image.h);
	all->sprite.rock1 = mlx_xpm_file_to_image(all->window.mlx_ptr,
			"./sprites/Rock-1.xpm", &all->image.w, &all->image.h);
	all->sprite.player.player = mlx_xpm_file_to_image(all->window.mlx_ptr,
			"./sprites/Player.xpm", &all->image.w, &all->image.h);
	all->sprite.beer = mlx_xpm_file_to_image(all->window.mlx_ptr,
			"./sprites/beer.xpm", &all->image.w, &all->image.h);
	all->sprite.exit = mlx_xpm_file_to_image(all->window.mlx_ptr,
			"./sprites/exit.xpm", &all->image.w, &all->image.h);
}
