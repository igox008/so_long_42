/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 06:15:42 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/14 07:17:02 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	animate_enemy(int x, int y, t_data **i)
{
	srand(time(NULL));
	void	*en;
	static int	j;
	int r = rand() % 4;

	if (r == 0 && (*i)->map[y + 1][x] != '1' && (*i)->map[y + 1][x] != 'C' && (*i)->map[y + 1][x] != 'E' && (*i)->map[y + 1][x] != 'P')
	{
		en = mlx_xpm_file_to_image((*i)->mlx_ptr, ENEMY_U, &(*i)->size, &(*i)->size);
		if (!en && mini_printf(0, "fix assets names"))
			close_window(*i);
		mlx_put_image_to_window((*i)->mlx_ptr, (*i)->mlx_win, en, x * 64, (y + 1) * 64);
		mlx_put_image_to_window((*i)->mlx_ptr, (*i)->mlx_win, (*i)->lava, x * 64, y * 64);
		(*i)->map[y][x] = '0';
		(*i)->map[y + 1][x] = 'N';
	}
	else if (r == 1 && (*i)->map[y][x + 1] != '1' && (*i)->map[y][x + 1] != 'C' && (*i)->map[y][x + 1] != 'E' && (*i)->map[y][x + 1] != 'P')
	{
		en = mlx_xpm_file_to_image((*i)->mlx_ptr, ENEMY_R, &(*i)->size, &(*i)->size);
		if (!en && mini_printf(0, "fix assets names"))
			close_window(*i);
		mlx_put_image_to_window((*i)->mlx_ptr, (*i)->mlx_win, en, (x + 1) * 64, y * 64);
		mlx_put_image_to_window((*i)->mlx_ptr, (*i)->mlx_win, (*i)->lava, x * 64, y * 64);
		(*i)->map[y][x] = '0';
		(*i)->map[y][x + 1] = 'N';
	}
	else if (r == 2 && (*i)->map[y][x - 1] != '1' && (*i)->map[y][x - 1] != 'C' && (*i)->map[y][x - 1] != 'E' && (*i)->map[y][x - 1] != 'P')
	{
		en = mlx_xpm_file_to_image((*i)->mlx_ptr, ENEMY_R, &(*i)->size, &(*i)->size);
		if (!en && mini_printf(0, "fix assets names"))
			close_window(*i);
		mlx_put_image_to_window((*i)->mlx_ptr, (*i)->mlx_win, en, (x - 1) * 64, y * 64);
		mlx_put_image_to_window((*i)->mlx_ptr, (*i)->mlx_win, (*i)->lava, x * 64, y * 64);
		(*i)->map[y][x] = '0';
		(*i)->map[y][x - 1] = 'N';
	}
	else if (r == 3 && (*i)->map[y - 1][x] != '1' && (*i)->map[y - 1][x] != 'C' && (*i)->map[y - 1][x] != 'E' && (*i)->map[y - 1][x] != 'P')
	{
		en = mlx_xpm_file_to_image((*i)->mlx_ptr, ENEMY_U, &(*i)->size, &(*i)->size);
		if (!en && mini_printf(0, "fix assets names"))
			close_window(*i);
		mlx_put_image_to_window((*i)->mlx_ptr, (*i)->mlx_win, en, x * 64, (y - 1) * 64);
		mlx_put_image_to_window((*i)->mlx_ptr, (*i)->mlx_win, (*i)->lava, x * 64, y * 64);
		(*i)->map[y][x] = '0';
		(*i)->map[y - 1][x] = 'N';
	}
	else
	{
		// mlx_put_image_to_window((*i)->mlx_ptr, (*i)->mlx_win, (*i)->lava, x * 64, y * 64);
		mlx_put_image_to_window((*i)->mlx_ptr, (*i)->mlx_win, ENEMY_D, x * 64, y * 64);
		if (j == 4)
			j = 0;
		// if (!i)
		// 	mlx_put_image_to_window((*i)->mlx_ptr, (*i)->mlx_win, ENEMY_D, x * 64, y * 64);
		// else if (!(i - 1))
		// 	mlx_put_image_to_window((*i)->mlx_ptr, (*i)->mlx_win, ENEMY_R, x * 64, y * 64);
		// else if (!(i - 2))
		// 	mlx_put_image_to_window((*i)->mlx_ptr, (*i)->mlx_win, ENEMY_U, x * 64, y * 64);
		// else if (!(i - 3))
		// 	mlx_put_image_to_window((*i)->mlx_ptr, (*i)->mlx_win, ENEMY_L, x * 64, y * 64);
		j++;
	}
	// for (int il = 0; (*i)->map[il]; il++)
	// {
	// 	printf("%s\n", (*i)->map[il]);
	// }
	// printf("----------------\n");
	// usleep(30000);
	mlx_do_sync((*i)->mlx_ptr);
}

int	move_enemy(t_data *info)
{
	int	y;
	int	x;

	y = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if (info->map[y][x] == 'N')
			{
				animate_enemy(x, y, &info);
				break;
			}
			x++;
		}
		y++;
	}
	return (1);
}