/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:39:17 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/15 19:39:30 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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