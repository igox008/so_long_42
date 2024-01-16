/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:54:48 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/15 13:21:30 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_moves(t_corr p, t_corr f, t_data ***info)
{
	mlx_image_t		*player;
	mlx_image_t		*floor;

	player = get_image(**info, PLAYER);
	floor = get_image(**info, LAVA);
	if (!player || !floor)
		close_window(**info, EXIT_FAILURE);
	if ((**info)->map[p.y][p.x] == 'C' && (**info)->coins--)
		mlx_image_to_window((**info)->i, floor, p.x * 64, p.y * 64);
	mlx_image_to_window((**info)->i, floor, f.x * 64, f.y * 64);
	mlx_image_to_window((**info)->i, player, p.x * 64, p.y * 64);
	(**info)->map[f.y][f.x] = '0';
	(**info)->map[p.y][p.x] = 'P';
	(**info)->moves_count++;
	mini_printf((**info)->moves_count, NULL);
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

void	mlx_fail(t_data	*i)
{
	int	j;

	j = 0;
	while (i->map[j])
	{
		free(i->map[j]);
		j++;
	}
	free(i->map);
	mini_printf(0, "something wrong happen");
	exit(EXIT_FAILURE);
}

mlx_image_t	*get_image(t_data *i, char *path)
{
	mlx_texture_t	*t;
	mlx_image_t		*im;

	t = mlx_load_png((const char *)path);
	if (!t)
		close_window(i, EXIT_FAILURE);
	im = mlx_texture_to_image(i->i, t);
	if (!im)
		close_window(i, EXIT_FAILURE);
	mlx_delete_texture(t);
	return (im);
}