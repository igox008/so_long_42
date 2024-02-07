/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:39:17 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/25 19:40:35 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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

int	frames(t_data *i)
{
	static int	n;

	if (i->coins <= 0 && !n++)
		open_exit(i);
	if (i->keyp == UP)
		move_up(i);
	else if (i->keyp == DOWN)
		move_down(i);
	else if (i->keyp == LEFT)
		move_left(i);
	else if (i->keyp == RIGHT)
		move_right(i);
	return (i->keyp);
}

t_boolean	check_last(char *all)
{
	int	i;

	if (!all)
		return (FALSE);
	i = ft_strlen(all);
	if (i > 0)
		i--;
	if (all[i] == '\n')
		return (FALSE);
	return (TRUE);
}
