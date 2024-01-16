/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 03:04:57 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/16 01:22:43 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	animate(int x, t_corr f, char *pt, t_data **i)
{
	mlx_image_t	*l;
	mlx_image_t	*mv;

	l = get_image(*i, LAVA);
	mv = get_image(*i, pt);
	if (mlx_image_to_window((*i)->i, l, f.x * 64, f.y * 64) < 0)
		mlx_fail(*i);
	// mlx_do_sync((*i)->i->context);
	if (mlx_image_to_window((*i)->i, mv, x, f.y * 64) < 0)
		mlx_fail(*i);
	mlx_flush_batch((mlx_ctx_t *)(*i)->i->context);
	usleep(10000);
	if (ft_strnstr(pt, "left", 200))
	{
		if (mlx_image_to_window((*i)->i, l, (f.x - 1) * 64,
			f.y * 64) < 0)
			mlx_fail(*i);
	}
	else
	{
		if (mlx_image_to_window((*i)->i, l, (f.x + 1) * 64,
			f.y * 64) < 0)
			mlx_fail(*i);
	}
}

void	animate_idle_helper(t_corr p, t_corr f, t_data **i, int y)
{
	mlx_image_t	*l;
	mlx_image_t	*mv;

	l = get_image(*i, LAVA);
	mv = get_image(*i, (*i)->dir);
	if (mlx_image_to_window((*i)->i, l, f.x * 64, f.y * 64) < 0 
		|| mlx_image_to_window((*i)->i, mv, f.x * 64, y) < 0)
		mlx_fail(*i);
	// mlx_do_sync((*i)->mlx_ptr);
	// usleep(30000);
	if (mlx_image_to_window((*i)->i, l, p.x * 64, p.y * 64) < 0)
		mlx_fail(*i);
}

void	animate_idle(t_corr p, t_corr f, t_data **i)
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
		mini_printf(0, RED UNDERLINE"mlx can't rander all this"RESET);
	else
	{
		mini_printf(0, UNDERLINE RED"ERROR INVALID MAP"RESET);
	}
	return (NULL);
}
