/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:21:23 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/25 19:50:56 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	listen_hook(int keyp, t_data *t)
{
	if (keyp == ESC)
	{
		mini_printf(1, GREEN"you pressed ESC"RESET);
		close_window(t, EXIT_SUCCESS);
	}
	else if (keyp == UP || keyp == 126)
		move_up(t);
	else if (keyp == DOWN || keyp == 125)
		move_down(t);
	else if (keyp == RIGHT || keyp == 124)
		move_right(t);
	else if (keyp == LEFT || keyp == 123)
		move_left(t);
	return (keyp);
}

int	close_window(t_data *f, int status)
{
	int	i;

	i = 0;
	if (f->ptr != NULL && f->win != NULL)
		mlx_destroy_window(f->ptr, f->win);
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
	void		*pic;
	char		*pic_path;

	i = 0;
	while (i < y_max)
	{
		j = 0;
		while (j < x_max)
		{
			mlx_put_image_to_window(f->ptr, f->win, img->img, j, i);
			pic_path = asset_getter(f->map);
			if (pic_path != NULL)
			{
				pic = get_image(f, pic_path, 64);
				mlx_put_image_to_window(f->ptr, f->win, pic, j, i);
				mlx_destroy_image(f->ptr, pic);
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
	i->size = 64;
	i->moves_count = 0;
	i->coins = coin_count(i->map);
	img.path = "mandatory/textures/lava.xpm";
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
		exit(2);
	mlx_start_engine(&info, &img);
	img.img = get_image(&info, img.path, 64);
	fill_win(&img, &info, img.width, img.height);
	mlx_hook(info.win, 17, 1L << 0, mlx_fail, &info);
	mlx_hook(info.win, 2, 1L << 0, listen_hook, &info);
	mlx_loop(info.ptr);
}
