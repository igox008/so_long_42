/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:19:53 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/26 05:39:58 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	get_rest(t_data *i)
{
	i->anim_r[20] = "bonus/textures/Jump_0.xpm";
	i->anim_r[21] = "bonus/textures/Jump_1.xpm";
	i->anim_r[22] = "bonus/textures/Jump_2.xpm";
	i->anim_r[23] = "bonus/textures/Jump_3.xpm";
	i->anim_r[24] = "bonus/textures/Jump_4.xpm";
	i->anim_r[25] = NULL;
}

void	he_won(t_data *i, int x, int y)
{
	void	*lava;
	void	*player;
	void	*door;
	int		t;
	int		m;

	lava = get_image(i, LAVA, 64);
	door = get_image(i, EXIT_OPEN, 64);
	(1) && (t = 20, m = 0, i->moves_count++, print_moves(i));
	while (t <= 25 && m < 3)
	{
		if (t == 25 && ++m)
			t = 20;
		player = get_image(i, i->anim_r[t], 64);
		mlx_put_image_to_window(i->ptr, i->win, lava, x * 64, y * 64);
		mlx_put_image_to_window(i->ptr, i->win, door, x * 64, y * 64);
		mlx_put_image_to_window(i->ptr, i->win, player, x * 64, y * 64);
		mlx_do_sync(i->ptr);
		usleep(90000);
		t++;
	}
	(1) && (mini_printf(i->moves_count, NULL),
		mini_printf(1, GREEN"You Won"RESET));
	final(i, TRUE);
	close_window(i, EXIT_SUCCESS);
}

int	print_moves(t_data *i)
{
	char	*count;

	if (i->bound.x > 3)
		mlx_put_image_to_window(i->ptr, i->win, i->moves, 0, 0);
	else
		mlx_put_image_to_window(i->ptr, i->win, i->moves_re, 0, 0);
	count = ft_itoa(i->moves_count);
	if (!count && mini_printf(2, RED"itoa fail"RESET))
		close_window(i, EXIT_FAILURE);
	mlx_string_put(i->ptr, i->win, 10, 24, 0x5B5D00, "MOVES: ");
	mlx_string_put(i->ptr, i->win, 80, 24, 0x5B5D00, count);
	free(count);
	return (0);
}

void	final(t_data *i, t_boolean won)
{
	void	*txt;
	int		x;
	int		y;

	x = ((i->bound.x * 64) / 10) * 3;
	y = ((i->bound.y * 64) / 11) * 3;
	txt = NULL;
	if (won && i->bound.x * 64 >= 400 && i->bound.y * 64 >= 280)
		txt = get_image(i, "bonus/textures/won.xpm", 256);
	if (!won && i->bound.x * 64 >= 400 && i->bound.y * 64 >= 352)
		txt = get_image(i, "bonus/textures/lose.xpm", 256);
	if (txt != NULL)
	{
		mlx_put_image_to_window(i->ptr, i->win, txt, x, y);
		mlx_do_sync(i->ptr);
		usleep(900000);
	}
}
