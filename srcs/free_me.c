/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:10:50 by fsantos2          #+#    #+#             */
/*   Updated: 2023/09/07 12:37:38 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_sprites_and_shit(t_all *all)
{
	mlx_destroy_image(all->window.mlx_ptr, all->sprite.beer);
	mlx_destroy_image(all->window.mlx_ptr, all->sprite.exit);
	mlx_destroy_image(all->window.mlx_ptr, all->sprite.player.player);
	mlx_destroy_image(all->window.mlx_ptr, all->sprite.rock0);
	mlx_destroy_image(all->window.mlx_ptr, all->sprite.rock1);
	mlx_destroy_image(all->window.mlx_ptr, all->sprite.tree0);
	mlx_destroy_image(all->window.mlx_ptr, all->sprite.tree1);
	mlx_destroy_image(all->window.mlx_ptr, all->sprite.wall);
	mlx_destroy_image(all->window.mlx_ptr, all->sprite.water1);
}
