/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 01:10:47 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/26 04:59:10 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	open_exit(t_data *info)
{
	t_corr	cor;
	void	*exit;
	void	*lava;

	cor = get_xy(info->map, 'E');
	lava = get_image(info, LAVA, 64);
	exit = get_image(info, EXIT_OPEN, 64);
	mlx_put_image_to_window(info->ptr, info->win, lava, cor.x * 64, cor.y * 64);
	mlx_put_image_to_window(info->ptr, info->win, exit, cor.x * 64, cor.y * 64);
	mlx_destroy_image(info->ptr, lava);
	mlx_destroy_image(info->ptr, exit);
}

char	*dir_getter(int key, t_data *f)
{
	if (key == RIGHT || key == 124)
		return ("bonus/textures/player_right.xpm");
	else if (key == LEFT || key == 123)
		return ("bonus/textures/player_left.xpm");
	return (f->dir);
}

void	render_moves(t_corr p, t_corr f, char *pl, t_data *i)
{
	void	*player;
	void	*floor;

	player = get_image(i, pl, 64);
	floor = get_image(i, LAVA, 64);
	if (i->map[p.y][p.x] == 'C' && i->coins--)
		mlx_put_image_to_window(i->ptr, i->win,
			floor, p.x * 64, p.y * 64);
	mlx_put_image_to_window(i->ptr, i->win, floor, f.x * 64, f.y * 64);
	mlx_put_image_to_window(i->ptr, i->win, player, p.x * 64, p.y * 64);
	i->map[f.y][f.x] = '0';
	i->map[p.y][p.x] = 'P';
	if (p.x != f.x || p.y != f.y)
	{
		i->moves_count++;
		mini_printf(i->moves_count, NULL);
		print_moves(i);
	}
	i->key_pressed++;
	mlx_destroy_image(i->ptr, floor);
	mlx_destroy_image(i->ptr, player);
}

void	animate_right(t_corr p, t_corr f, t_data *info)
{
	int		i;
	int		x;

	i = 0;
	(void)p;
	while (i < 8)
	{
		x = (f.x * 64) + (8 * i);
		animate(x, f, info->anim_r[i], info);
		i++;
	}
}

void	animate_left(t_corr p, t_corr f, t_data *info)
{
	int		i;
	int		x;

	i = 8;
	(void)p;
	while (i < 16)
	{
		x = (f.x * 64) - (8 * (i - 8));
		animate(x, f, info->anim_r[i], info);
		i++;
	}
}
