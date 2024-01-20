/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 06:15:42 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/20 07:12:28 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*enemy_think(t_data *i, t_corr ene)
{
	static int  x;

	if (ene.x - 1 > 0 && i->map[ene.y][ene.x - 1] != '0')
		x = 0;
	if (ene.x + 1 < i->bound.x && i->map[ene.y][ene.x + 1] == '0' && x == 0){
		i->d = 'R';
		return (ENEMY_R);
	}
	else if (ene.x - 1 > 0 && i->map[ene.y][ene.x - 1] == '0') {
		x = 1;
		i->d = 'L';
		return (ENEMY_L);
	}
	i->d = 'U';
	return (ENEMY_U);
}

void	enemy_move(t_data *i, t_corr ene)
{
	char	*path;
	int		x;

	path = enemy_think(i, ene);
	if (ft_strnstr(path, "_left", 100))
		x = (ene.x - 1);
	else if (ft_strnstr(path, "_right", 100))
		x = (ene.x + 1);
	else
	{
		x = ene.x;
		return ;
	}
	i->map[ene.y][ene.x] = '0';
	i->map[ene.y][x] = 'N';
}

void	enemy_engine(t_data *i)
{
	t_corr	cor;

	cor.y = 0;
	while (i->map[cor.y])
	{
		cor.x = 0;
		while (i->map[cor.y][cor.x])
		{
			if (i->map[cor.y][cor.x] == 'N')
			{
				enemy_move(i, cor);
				i->old_ene = cor;
			}
			cor.x++;
			if (i->d == 'R' && cor.x + 1 < i->bound.x)
				cor.x++;
		}
		// printf("%s\n", i->map[cor.y]);
		cor.y++;
	}
}

void	*enemy_call(void *t)
{
	t_data	*i;

	i = (t_data *)t;
	i->old_ene.x = -1;
	i->old_ene.y = -1;
	while (1)
	{
		if (i->t_exit == 1)
			pthread_exit(NULL);
		enemy_engine(i);
		usleep(150000);
	}
	return (NULL);
}

void	render_enemy(t_data *i)
{
	void	*lava;
	void	*enemy;
	t_corr	c;

	c.y = 0;
	lava = get_image(i, LAVA, 64);
	enemy = get_image(i, ENEMY_D, 64);
	while (i->map[c.y])
	{
		c.x = 0;
		while (i->map[c.y][c.x])
		{
			if (i->map[c.y][c.x] == 'N')
			{
				if (i->old_ene.x != -1)
					mlx_put_image_to_window(i->ptr, i->win, lava, i->old_ene.x * 64, i->old_ene.y * 64);
				mlx_put_image_to_window(i->ptr, i->win, lava, c.x * 64, c.y * 64);
				mlx_put_image_to_window(i->ptr, i->win, enemy, c.x * 64, c.y * 64);
			}
			c.x++;
		}
		c.y++;
	}
	// mlx_destroy_image(i->ptr, lava);
	// mlx_destroy_image(i->ptr, enemy);
}