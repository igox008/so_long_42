/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 06:15:42 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/18 04:26:41 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char *enemy_dir(int index)
{
	static int	t[10240];

	if (t[index] > 3)
		t[index] = 0;
	if (t[index] == 0)
		return (ENEMY_D);
	else if (t[index] == 1)
		return (ENEMY_R);
	else if (t[index] == 2)
		return (ENEMY_U);
	else if (t[index] == 3)
		return (ENEMY_L);
	t[index]++;
	return (NULL);
}

void	rush_enemy(t_data *i, t_corr c, char *path)
{
	void	*lava;
	void	*enemy;

	lava = get_image(i, LAVA, 64);
	enemy = get_image(i, path, 64);
	mlx_put_image_to_window(i->ptr, i->win, lava, c.x * 64, c.y * 64);
	mlx_put_image_to_window(i->ptr, i->win, enemy, c.x * 64, c.y * 64);
	mlx_do_sync(i->ptr);
}
void	animate_enemy(t_data *i, t_corr c, int t)
{
	char	*path;

	path = enemy_dir(t);
	if (!path)
		return;
	if (!ft_strncmp(path, ENEMY_R, 100))
		rush_enemy(i, c, path);
	else if (!ft_strncmp(path, ENEMY_D, 100))
		rush_enemy(i, c, path);
	else if (!ft_strncmp(path, ENEMY_U, 100))
		rush_enemy(i, c, path);
	else if (!ft_strncmp(path, ENEMY_L, 100))
		rush_enemy(i, c, path);
}

void	enemy_to_move(t_data *i)
{
	t_corr	c;
	int		t;

	c.y = 0;
	t = 0;
	while (i->map[c.y])
	{
		c.x = 0;
		while (i->map[c.y][c.x])
		{
			if (i->map[c.y][c.x] == 'N')
			{
				animate_enemy(i, c, t);
				t++;
			}
			c.x++;
		}
		c.y++;
	}
}
