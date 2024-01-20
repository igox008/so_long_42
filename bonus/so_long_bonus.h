/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:02:09 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/20 07:51:20 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <math.h>
# include "libft-custom/libft.h"
# include "libft-custom/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <pthread.h>
// # include "../MLX42/include/MLX42/MLX42.h"
// # include "../MLX42/include/MLX42/MLX42_Int.h"
# include <time.h>

typedef int	t_boolean;

# define ESC 53
# define UP 13
# define RIGHT 2
# define LEFT 0
# define DOWN 1
# define TRUE 1
# define FALSE 0

# define P_R "bonus/assets/player_right.xpm"
# define P_L "bonus/assets/player_left.xpm"
# define EXIT_OPEN "bonus/assets/exit_open.xpm"
# define EXIT_CLOSE "bonus/assets/exit_close.xpm"
# define WALL "bonus/assets/wall.xpm"
# define COIN "bonus/assets/coin.xpm"
# define LAVA "bonus/assets/lava.xpm"
# define ENEMY_L "bonus/assets/enemy_left.xpm"
# define ENEMY_R "bonus/assets/enemy_right.xpm"
# define ENEMY_U "bonus/assets/enemy_up.xpm"
# define ENEMY_D "bonus/assets/enemy_down.xpm"

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

typedef struct s_corr
{
	int	x;
	int	y;
}	t_corr;

typedef struct s_data
{
	void	*ptr;
	void	*win;
	void	*lava;
	int		moves_count;
	int		size;
	int		coins;
	char	**map;
	char	*dir;
	int		key_pressed;
	char	*anim_r[23];
	int		keyp;
	int		t_exit;
	char	d;
	pthread_t	tid;
	t_corr	bound;
	t_corr	old_ene;
	clock_t	enemy;
	clock_t	cur;
}	t_data;

typedef struct s_img
{
	char			*path;
	int				width;
	int				height;
	void			*lava;
}	t_img;



typedef struct s_map
{
	char			*map;
	struct s_map	*next;
}	t_map;

void		incr(int *arr, char c);
t_boolean	check_last(char *all);
char		**special_handler(int i, char *all);
t_boolean	check_ext(char *str);
t_boolean	map_chek(char **str, int last);
t_boolean	a_o(char *first, char *last);
t_corr		get_xy(char **map, char c);
char		**arr_fail(char **array, size_t row);
char		**copy_map(char **map, int last);
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
void		open_exit(t_data *info);
char		*dir_getter(int key, t_data *f);
void		render_moves(t_corr p, t_corr f, char *pl, t_data ***info);
void		fill_animation_path(t_data **i);
void		animate_right(t_corr p, t_corr f, t_data **info);
void		animate_left(t_corr p, t_corr f, t_data **info);
void		animate(int x, t_corr f, char *pt, t_data **i);
void		animate_idle(t_corr p, t_corr f, t_data **i);
void		*get_image(t_data *i, char *path, int size);
int			mlx_fail(t_data	*i);
void		mlX_start_engine(t_data *i, t_img *m);
int			frames(t_data *i);
void		*enemy_call(void *t);
void		render_enemy(t_data *i);

#endif