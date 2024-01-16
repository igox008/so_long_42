/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 01:10:47 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/15 23:15:45 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	open_exit(t_data *info)
{
	t_corr	cor;
	mlx_image_t	*exit;
	mlx_image_t	*lava;

	cor = get_xy(info->map, 'E');
	lava = get_image(info, LAVA);
	exit = get_image(info, EXIT_OPEN);
	if (mlx_image_to_window(info->i, lava, cor.x * 64, cor.y * 64) < 0
		|| mlx_image_to_window(info->i, exit, cor.x * 64, cor.y * 64) < 0)
		mlx_fail(info);
}

char	*dir_getter(int key, t_data *f)
{
	if (key == MLX_KEY_D)
		return ("bonus/assets/player_right.png");
	else if (key == MLX_KEY_A)
		return ("bonus/assets/player_left.png");
	return (f->dir);
}

void	render_moves(t_corr p, t_corr f, char *pl, t_data ***info)
{
	mlx_image_t	*player;
	mlx_image_t	*floor;

	player = get_image(**info, pl);
	floor = get_image(**info, LAVA);
	if ((**info)->map[p.y][p.x] == 'C' && (**info)->coins--)
		if (mlx_image_to_window((**info)->i, floor, p.x * 64, p.y * 64) < 0)
			mlx_fail(**info);
	if (mlx_image_to_window((**info)->i, floor, f.x * 64, f.y * 64) < 0
		|| mlx_image_to_window((**info)->i, player, p.x * 64, p.y * 64) < 0)
		mlx_fail(**info);
	(**info)->map[f.y][f.x] = '0';
	(**info)->map[p.y][p.x] = 'P';
	if (p.x != f.x || p.y != f.y)
	{
		(**info)->moves_count++;
		mini_printf((**info)->moves_count, NULL);
	}
	(**info)->key_pressed++;
}

void	animate_right(t_corr p, t_corr f, t_data **info)
{
	int		i;
	int		x;

	i = 0;
	(void)p;
	while (i < 8)
	{
		x = (f.x * 64) + (8 * i);
		animate(x, f, (*info)->anim_r[i], info);
		i++;
	}
}

void	animate_left(t_corr p, t_corr f, t_data **info)
{
	int		i;
	int		x;

	i = 8;
	(void)p;
	while (i < 16)
	{
		x = (f.x * 64) - (8 * (i - 8));
		animate(x, f, (*info)->anim_r[i], info);
		i++;
	}
}
