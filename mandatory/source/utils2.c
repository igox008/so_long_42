/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:54:48 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/25 19:42:16 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_moves(t_corr p, t_corr f, t_data *t)
{
	void		*player;
	void		*floor;

	player = get_image(t, PLAYER, 64);
	floor = get_image(t, LAVA, 64);
	if (t->map[p.y][p.x] == 'C' && t->coins--)
		mlx_put_image_to_window(t->ptr, t->win, floor, p.x * 64, p.y * 64);
	mlx_put_image_to_window(t->ptr, t->win, player, p.x * 64, p.y * 64);
	mlx_put_image_to_window(t->ptr, t->win, floor, f.x * 64, f.y * 64);
	t->map[f.y][f.x] = '0';
	t->map[p.y][p.x] = 'P';
	t->moves_count++;
	mini_printf(t->moves_count, NULL);
}

char	**special_handler(int i, char *all)
{
	if (all)
		free(all);
	if (i > 128)
		mini_printf(2, RED UNDERLINE"mlx can't rander all this"RESET);
	else
		mini_printf(2, UNDERLINE RED"ERROR INVALID MAP"RESET);
	return (NULL);
}

int	mlx_fail(t_data	*i)
{
	int	j;

	j = 0;
	while (i->map[j])
	{
		free(i->map[j]);
		j++;
	}
	free(i->map);
	mlx_destroy_window(i->ptr, i->win);
	mini_printf(1, "you Pressed"RED" X "RESET"button");
	exit(0);
}

void	*get_image(t_data *i, char *path, int size)
{
	void	*img;

	img = mlx_xpm_file_to_image(i->ptr, path, &size, &size);
	if (!img)
	{
		mini_printf(2, RED"asset LOAD fail!!!"RESET);
		close_window(i, EXIT_FAILURE);
	}
	return (img);
}

void	mlx_start_engine(t_data *i, t_img *m)
{
	i->ptr = mlx_init();
	if (!i->ptr)
	{
		mini_printf(2, RED"ERROR\nmlx init fail"RESET);
		close_window(i, EXIT_FAILURE);
	}
	i->win = mlx_new_window(i->ptr, m->width, m->height, "so_long");
	if (!i->win)
	{
		mini_printf(2, RED"ERROR\nmlx new window fail"RESET);
		close_window(i, EXIT_FAILURE);
	}
}
