/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:02:09 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/15 13:20:52 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include "libft-custom/libft.h"
# include "libft-custom/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include "../MLX42/include/MLX42/MLX42.h"

typedef int	t_boolean;

# define ESC 53
# define UP 13
# define RIGHT 2
# define LEFT 0
# define DOWN 1
# define TRUE 1
# define FALSE 0

# define PLAYER "mandatory/assets/player.png"
# define EXIT_CLOSE "mandatory/assets/exit.png"
# define WALL "mandatory/assets/wall.png"
# define COIN "mandatory/assets/coin.png"
# define LAVA "mandatory/assets/lava.png"

# define RESET "\x1b[0m"
# define BOLD "\x1b[1m"
# define UNDERLINE "\x1b[4m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define BG_BLUE "\x1b[44m"

typedef struct s_data
{
	mlx_t	*i;
	int		moves_count;
	int		size;
	int		coins;
	char	**map;
}	t_data;

typedef struct s_img
{
	char			*path;
	int				width;
	int				height;
	mlx_texture_t	*txt;
	mlx_image_t		*img;
}	t_img;

typedef struct s_corr
{
	int	x;
	int	y;
}	t_corr;

typedef struct s_map
{
	char			*map;
	struct s_map	*next;
}	t_map;

void		incr(int *arr, char c);
char		**special_handler(int i, char *all);
t_boolean	check_ext(char *str);
t_boolean	map_chek(char **str, int last);
t_boolean	a_o(char *first, char *last);
t_corr		get_xy(char **map, char c);
char		**arr_fail(char **array, size_t row);
char		**copy_map(char **map, int last);
void		mlx_fail(t_data	*i);
t_boolean	skip(char c);
void		flood(char **map, size_t x, size_t y, size_t rows);
t_boolean	flood_fill_it(char **map, size_t rows);
char		**parse_main(int ac, char **av);
t_corr		width_height(char **map);
void		fill_win(t_img *img, t_data *f, int x_max, int y_max);
char		*asset_getter(char	**map);
void		move_up(t_data **info);
void		move_down(t_data **info);
void		move_right(t_data **info);
void		move_left(t_data **info);
int			mini_printf(int n, char *str);
int			coin_count(char **map);
int			close_window(t_data *f, int status);
void		render_moves(t_corr p, t_corr f, t_data ***info);
mlx_image_t	*get_image(t_data *i, char *path);

#endif