/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:21:23 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/26 21:19:09 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	listen_hook(int keyp, t_data *t)
{
	if (t->key_pressed == 0)
		t->dir = "bonus/textures/player_right.xpm";
	if (keyp == ESC)
	{
		mini_printf(1, GREEN"you pressed ESC"RESET);
		close_window(t, EXIT_SUCCESS);
	}
	else if (keyp == UP || keyp == 126)
		t->keyp = UP;
	else if (keyp == DOWN || keyp == 125)
		t->keyp = DOWN;
	else if (keyp == RIGHT || keyp == 124)
		t->keyp = RIGHT;
	else if (keyp == LEFT || keyp == 123)
		t->keyp = LEFT;
	t->dir = dir_getter(keyp, t);
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
	t_corr		c;
	void		*pic;
	char		*pic_path;

	c.y = 0;
	while (c.y < y_max)
	{
		c.x = 0;
		while (c.x < x_max)
		{
			mlx_put_image_to_window(f->ptr, f->win, img->lava, c.x, c.y);
			pic_path = asset_getter(f->map);
			if (pic_path != NULL)
			{
				pic = get_image(f, pic_path, 64);
				mlx_put_image_to_window(f->ptr, f->win, pic, c.x, c.y);
				mlx_destroy_image(f->ptr, pic);
			}
			c.x += 64;
		}
		c.y += 64;
	}
}

t_img	initial_check(int ac, char **av, t_data *i)
{
	t_img	img;

	i->map = parse_main(ac, av);
	if (!i->map)
		return (img.height = -1, img);
	i->bound = width_height(i->map);
	i->size = 64;
	i->moves_count = 0;
	i->coins = c_count(i->map, 'C');
	i->ene_cnt = c_count(i->map, 'N');
	img.path = "bonus/textures/lava.xpm";
	img.height = 64 * i->bound.y;
	img.width = 64 * i->bound.x;
	i->keyp = -1;
	i->key_pressed = 0;
	i->d = 'U';
	fill_animation_path(&i);
	return (img);
}

int	main(int ac, char **av)
{
	t_data		info;
	t_img		img;

	img = initial_check(ac, av, &info);
	if (!info.map)
		return (0);
	mlx_start_engine(&info, &img);
	check_txt(&info);
	img.lava = get_image(&info, img.path, 64);
	fill_win(&img, &info, img.width, img.height);
	mlx_hook(info.win, 17, 1L << 0, mlx_fail, &info);
	mlx_hook(info.win, 2, 1L << 0, listen_hook, &info);
	mlx_loop_hook(info.ptr, frames, &info);
	info.moves = get_image(&info, "bonus/textures/score.xpm", 64);
	info.moves_re = get_image(&info, "bonus/textures/score_re.xpm", 64);
	print_moves(&info);
	mlx_loop(info.ptr);
}
