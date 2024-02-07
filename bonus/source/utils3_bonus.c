/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 03:04:57 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/26 20:36:27 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	animate(int x, t_corr f, char *pt, t_data *i)
{
	void	*l;
	void	*mv;

	l = get_image(i, LAVA, 64);
	mv = get_image(i, pt, 64);
	mlx_put_image_to_window(i->ptr, i->win, l, f.x * 64, f.y * 64);
	mlx_put_image_to_window(i->ptr, i->win, mv, x, f.y * 64);
	mlx_do_sync(i->ptr);
	usleep(10000);
	if (ft_strnstr(pt, "left", 200))
		mlx_put_image_to_window(i->ptr, i->win, l,
			(f.x - 1) * 64, f.y * 64);
	else
		mlx_put_image_to_window(i->ptr, i->win, l,
			(f.x + 1) * 64, f.y * 64);
	mlx_destroy_image(i->ptr, l);
	mlx_destroy_image(i->ptr, mv);
}

void	animate_idle_helper(t_corr p, t_corr f, t_data *i, int y)
{
	void	*l;
	void	*mv;

	l = get_image(i, LAVA, 64);
	mv = get_image(i, i->dir, 64);
	mlx_put_image_to_window(i->ptr, i->win, l, f.x * 64, f.y * 64);
	mlx_put_image_to_window(i->ptr, i->win, mv, f.x * 64, y);
	mlx_do_sync(i->ptr);
	usleep(10000);
	mlx_put_image_to_window(i->ptr, i->win, l, p.x * 64, p.y * 64);
	mlx_destroy_image(i->ptr, l);
	mlx_destroy_image(i->ptr, mv);
}

void	animate_idle(t_corr p, t_corr f, t_data *i)
{
	int		t;
	int		y;

	t = 16;
	while (t < 22)
	{
		if (f.y < p.y && t != 21)
			y = (f.y * 64) + (13 * (t - 16));
		else if (f.y < p.y && t == 21)
			y = (f.y * 64) + (12 * (t - 16));
		else if (f.y > p.y && t != 21)
			y = (f.y * 64) - (13 * (t - 16));
		else if (f.y > p.y && t == 21)
			y = (f.y * 64) - (12 * (t - 16));
		animate_idle_helper(p, f, i, y);
		t++;
	}
}

char	**special_handler(int i, char *all)
{
	if (all)
		free(all);
	if (i > 128)
		mini_printf(2, RED UNDERLINE"mlx can't rander all this"RESET);
	else
	{
		mini_printf(2, UNDERLINE RED"ERROR INVALID MAP"RESET);
	}
	exit(EXIT_FAILURE);
	return (NULL);
}

void	he_lose(t_data *i, int x, int y)
{
	void	*ene;
	void	*lava;
	void	*player;
	int		t;
	t_corr	cor;

	ene = get_image(i, ENEMY_ON, 64);
	lava = get_image(i, LAVA, 64);
	t = 16;
	cor = get_xy(i->map, 'P');
	i->moves_count++;
	print_moves(i);
	mlx_put_image_to_window(i->ptr, i->win, lava, x * 64, y * 64);
	mlx_put_image_to_window(i->ptr, i->win, ene, x * 64, y * 64);
	while (t < 20)
	{
		player = get_image(i, i->anim_r[t], 64);
		mlx_put_image_to_window(i->ptr, i->win, lava, cor.x * 64, cor.y * 64);
		mlx_put_image_to_window(i->ptr, i->win, player, cor.x * 64, cor.y * 64);
		mlx_do_sync(i->ptr);
		usleep(120000);
		t++;
	}
	final(i, FALSE);
	close_window(i, 0);
}
