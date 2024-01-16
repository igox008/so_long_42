/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:21:23 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/15 13:20:48 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	f(int key, t_data *t)
void	listen_hook(mlx_key_data_t keyp, void *p)
{
	t_data	*t;

	t = (t_data *)p;
	if (keyp.key == MLX_KEY_ESCAPE  && keyp.action == MLX_PRESS)
	{
		mini_printf(0, GREEN"you pressed ESC"RESET);
		close_window(t, EXIT_SUCCESS);
	}
	else if (keyp.key == MLX_KEY_W && keyp.action == MLX_PRESS)
		move_up(&t);
	else if (keyp.key == MLX_KEY_S && keyp.action == MLX_PRESS)
		move_down(&t);
	else if (keyp.key == MLX_KEY_D && keyp.action == MLX_PRESS)
		move_right(&t);
	else if (keyp.key == MLX_KEY_A && keyp.action == MLX_PRESS)
		move_left(&t);
	// return (NULL);
}

int	close_window(t_data *f, int status)
{
	int	i;

	i = 0;
	// mlx_destroy_window(f->mlx_ptr, f->mlx_win);
	mlx_close_window(f->i);
	mlx_terminate(f->i);
	while (f->map[i])
	{
		free(f->map[i]);
		i++;
	}
	free(f->map);
	exit(status);
	return (0);
}

void	fill_win(t_img *img, t_data *f, int x_max, int y_max)
{
	int			i;
	int			j;
	mlx_image_t	*pic;
	char		*pic_path;

	i = 0;
	while (i < y_max)
	{
		j = 0;
		while (j < x_max)
		{
			if (mlx_image_to_window(f->i, img->img, j, i) < 0)
				close_window(f, EXIT_FAILURE);
			pic_path = asset_getter(f->map);
			if (pic_path != NULL)
			{
				pic = get_image(f, pic_path);
				if ((!pic && mini_printf(0, "fix assets names"))
					|| mlx_image_to_window(f->i, pic, j, i) < 0)
					close_window(f, EXIT_FAILURE);
			}
			j += 64;
		}
		i += 64;
	}
}

t_img	initial_check(int ac, char **av, t_data *i)
{
	t_corr	boundaries;
	t_img	img;

	i->map = parse_main(ac, av);
	if (!i->map)
		return (img.height = -1, img);
	boundaries = width_height(i->map);
	if (boundaries.x > 129 || boundaries.y > 127)
		return (arr_fail(i->map, boundaries.y), img.width = -1,
			ft_putendl_fd(UNDERLINE RED"mlx cannot handle this map"RESET, 1),
			img);
	i->size = 64;
	i->moves_count = 0;
	i->coins = coin_count(i->map);
	img.path = "mandatory/assets/lava.png";
	img.height = 64 * boundaries.y;
	img.width = 64 * boundaries.x;
	return (img);
}


int	main(int ac, char **av)
{
	t_data	info;
	t_img	img;	
	
	img = initial_check(ac, av, &info);
	if (!info.map)
		return (0);
	info.i = mlx_init(img.width, img.height, "so_long", FALSE);
	if (!info.i)
		mlx_fail(&info);
	img.img = get_image(&info, img.path);
	fill_win(&img, &info, img.width, img.height);
	mlx_key_hook(info.i, listen_hook, &info);
	// mlx_hook(info.i->window, 17, 0, close_window, &info);
	mlx_loop(info.i);
}
