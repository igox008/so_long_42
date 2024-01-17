/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:21:23 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/18 00:17:40 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	listen_hook(int keyp, t_data *t)
{
	if (t->key_pressed == 0)
		t->dir = "bonus/assets/player_right.xpm";
	if (keyp == ESC)
	{
		mini_printf(0, GREEN"you pressed ESC"RESET);
		close_window(t, EXIT_SUCCESS);
	}
	else if (keyp == UP)
		t->keyp = UP;
	else if (keyp == DOWN)
		t->keyp = DOWN;
	else if (keyp == RIGHT)
		t->keyp = RIGHT;
	else if (keyp == LEFT)
		t->keyp = LEFT;
	if (t->coins <= 0)
		open_exit(t);
	t->dir = dir_getter(keyp, t);
	return (keyp);
}

int	close_window(t_data *f, int status)
{
	int	i;

	i = 0;
	if (f->ptr != NULL && f->win != NULL)
		mlx_destroy_window(f->ptr, f->win);
	// mlx_close_window(f->i);
	// mlx_terminate(f->i);
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
			mlx_put_image_to_window(f->ptr, f->win, img->lava, j, i);
			pic_path = asset_getter(f->map);
			if (pic_path != NULL)
			{
				pic = get_image(f, pic_path, 64);
				if (!pic && mini_printf(0, "fix assets names"))
					close_window(f, EXIT_FAILURE);
				mlx_put_image_to_window(f->ptr, f->win, pic, j, i);
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
	img.path = "bonus/assets/lava.xpm";
	img.height = 64 * boundaries.y;
	img.width = 64 * boundaries.x;
	i->keyp = -1;
	i->cur = clock();
	fill_animation_path(&i);
	return (img);
}


int	main(int ac, char **av)
{
	t_data	info;
	t_img	img;	
	
	img = initial_check(ac, av, &info);
	if (!info.map)
		return (0);
	mlX_start_engine(&info, &img);
	img.lava = get_image(&info, img.path, 64);
	fill_win(&img, &info, img.width, img.height);
	mlx_hook(info.win, 17, 1L<<0, mlx_fail, &info);
	mlx_key_hook(info.win, listen_hook, &info);
	mlx_loop_hook(info.ptr, frames, &info);
	mlx_loop(info.ptr);
}

