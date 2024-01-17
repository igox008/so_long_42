/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 03:04:57 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/18 00:18:24 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	animate(int x, t_corr f, char *pt, t_data **i)
{
	void	*l;
	void	*mv;

	l = get_image(*i, LAVA, 64);
	mv = get_image(*i, pt, 64);
	mlx_put_image_to_window((*i)->ptr, (*i)->win, l, f.x * 64, f.y * 64);
	mlx_put_image_to_window((*i)->ptr, (*i)->win, mv, x, f.y * 64);
	mlx_do_sync((*i)->ptr);
	// usleep(10000);
	if (ft_strnstr(pt, "left", 200))
		mlx_put_image_to_window((*i)->ptr, (*i)->win, l, (f.x - 1) * 64,f.y * 64);
	else
		mlx_put_image_to_window((*i)->ptr, (*i)->win, l, (f.x + 1) * 64,f.y * 64);
}

void	animate_idle_helper(t_corr p, t_corr f, t_data **i, int y)
{
	void	*l;
	void	*mv;

	l = get_image(*i, LAVA, 64);
	mv = get_image(*i, (*i)->dir, 64);
	mlx_put_image_to_window((*i)->ptr, (*i)->win, l, f.x * 64, f.y * 64);
	mlx_put_image_to_window((*i)->ptr, (*i)->win, mv, f.x * 64, y);
	mlx_do_sync((*i)->ptr);
	// usleep(10000);
	mlx_put_image_to_window((*i)->ptr, (*i)->win, l, p.x * 64, p.y * 64);
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
