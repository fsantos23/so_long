/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:35:35 by fsantos2          #+#    #+#             */
/*   Updated: 2023/09/07 12:45:19 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <X11/X.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>

# define ESCAPE 65307
# define SIZE 32
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_coor
{
	int			x;
	int			y;
}				t_coor;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_coor		coor;
}				t_win;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			h;
	int			w;
	int			bpp;
	int			endian;
	int			line_len;
}				t_img;

typedef struct s_play
{
	void		*player;
	int			x;
	int			y;
}				t_play;

typedef struct s_sprite
{
	void		*wall;
	void		*floor;
	void		*door;
	void		*water1;
	void		*tree0;
	void		*tree1;
	void		*rock0;
	void		*rock1;
	void		*beer;
	void		*exit;
	t_play		player;
}				t_sprite;

typedef struct s_map
{
	char		**map;
}				t_map;

typedef struct s_count
{
	int			count_coll;
	int			count_exit;
	int			count_all;
}				t_count;

typedef struct s_fdfile
{
	char		*fd_file;
}				t_fdfile;

typedef struct s_moves
{
	int			moves;
}				t_moves;

typedef struct s_all
{
	t_img		image;
	t_win		window;
	t_sprite	sprite;
	t_map		map;
	t_fdfile	fd;
	t_moves		moves;
	t_count		count;
	int			lines;
}				t_all;

t_win			create_window(void *mlx_ptr, void *mlx_win, int height,
					int width);
t_img			new_image(t_win window);
void			ft_exit(t_all *all);
int				exit_window(int keycode, t_all *all);
void			ft_put_wall(int x, int y, t_all all);
void			read_map(char **map, t_all all);
void			set_background(char *path, t_all *all);
void			start_game(t_all *all, int fd);
void			*ft_new_layout(void *mlx_ptr, char *path);
void			check_layout(t_all *all);
void			ft_check_sprite(char str, t_all *all, int x, int y);
void			ft_xpm_to_image(t_all *all);
void			map_size(t_all *all, int fd);
int				check_player(int keycode, t_all *all, int *x, int *y);
int				num_lines(int fd);
int				check_wall(t_all *all, char map);
int				check_collect(char **map);
int				check_exit(t_all *all, char map);
int				rectangle(t_all *all);
int				check_map(t_all *all);
int				fill(t_all *all);
void			flood_fill(int x, int y, char **map, int *counter);
void			counter_collectibles(t_all *all);
void			free_array(char **map);
void			free_sprites_and_shit(t_all *all);
int				exit_cross(t_all *all);
int				move_player(int keycode, t_all *all, int *x, int *y);
int				move_up(t_all *all, int *x, int *y);
int				move_left(t_all *all, int *x, int *y);
int				move_down(t_all *all, int *x, int *y);
int				move_right(t_all *all, int *x, int *y);
int				check_letters(char letter);

#endif