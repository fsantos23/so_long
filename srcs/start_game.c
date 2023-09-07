/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 03:25:17 by fsantos2          #+#    #+#             */
/*   Updated: 2023/09/07 13:28:47 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	start_game(t_all *all, int fd)
{
	map_size(all, fd);
	counter_collectibles(all);
	if (rectangle(all) == -1 || check_map(all) == -1 || fill(all) == -1)
	{
		free_array(all->map.map);
		free(all);
		write(1, "Error\n", 6);
		exit(1);
	}
	all->window.mlx_ptr = mlx_init();
	all->window.mlx_win = mlx_new_window(all->window.mlx_ptr, SIZE \
			* all->window.coor.x, SIZE * all->window.coor.y, "drunk guy");
	ft_xpm_to_image(all);
	set_background("./sprites/background.xpm", all);
	check_layout(all);
	all->moves.moves = 0;
	ft_exit(all);
	mlx_loop(all->window.mlx_ptr);
}

void	set_background(char *path, t_all *all)
{
	t_img	bg_img;
	char	**map;
	int		i;
	int		j;

	map = all->map.map;
	bg_img.img_ptr = ft_new_layout(all->window.mlx_ptr, path);
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			mlx_put_image_to_window(all->window.mlx_ptr, all->window.mlx_win, \
					bg_img.img_ptr, SIZE * i, SIZE * j);
			i++;
		}
		j++;
	}
	mlx_destroy_image(all->window.mlx_ptr, bg_img.img_ptr);
}

void	*ft_new_layout(void *mlx_ptr, char *path)
{
	t_img	bg;

	bg.img_ptr = mlx_xpm_file_to_image(mlx_ptr, path, &bg.w, &bg.h);
	return (bg.img_ptr);
}
