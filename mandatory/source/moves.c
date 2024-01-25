/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:42:54 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/25 19:41:29 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_data *info)
{
	t_corr	to_p;
	t_corr	to_f;

	to_f = get_xy(info->map, 'P');
	if (info->map[to_f.y - 1][to_f.x] == '0' ||
		info->map[to_f.y - 1][to_f.x] == 'C')
	{
		to_p.x = to_f.x;
		to_p.y = to_f.y - 1;
		render_moves(to_p, to_f, info);
	}
	else if (info->map[to_f.y - 1][to_f.x] == 'E' && info->coins <= 0)
	{
		info->moves_count++;
		mini_printf(info->moves_count, NULL);
		mini_printf(1, GREEN"You Won"RESET);
		close_window(info, EXIT_SUCCESS);
	}
}

void	move_down(t_data *info)
{
	t_corr	to_p;
	t_corr	to_f;

	to_f = get_xy(info->map, 'P');
	if (info->map[to_f.y + 1][to_f.x] == '0' ||
		info->map[to_f.y + 1][to_f.x] == 'C')
	{
		to_p.x = to_f.x;
		to_p.y = to_f.y + 1;
		render_moves(to_p, to_f, info);
	}
	else if (info->map[to_f.y + 1][to_f.x] == 'E' && info->coins <= 0)
	{
		info->moves_count++;
		mini_printf(info->moves_count, NULL);
		mini_printf(1, GREEN"You Won"RESET);
		close_window(info, EXIT_SUCCESS);
	}
}

void	move_right(t_data *info)
{
	t_corr	to_p;
	t_corr	to_f;

	to_f = get_xy(info->map, 'P');
	if (info->map[to_f.y][to_f.x + 1] == '0' ||
		info->map[to_f.y][to_f.x + 1] == 'C')
	{
		to_p.x = to_f.x + 1;
		to_p.y = to_f.y;
		render_moves(to_p, to_f, info);
	}
	else if (info->map[to_f.y][to_f.x + 1] == 'E' && info->coins <= 0)
	{
		info->moves_count++;
		mini_printf(info->moves_count, NULL);
		mini_printf(1, GREEN"You Won"RESET);
		close_window(info, EXIT_SUCCESS);
	}
}

void	move_left(t_data *info)
{
	t_corr	to_p;
	t_corr	to_f;

	to_f = get_xy(info->map, 'P');
	if (info->map[to_f.y][to_f.x - 1] == '0' ||
		info->map[to_f.y][to_f.x - 1] == 'C')
	{
		to_p.x = to_f.x - 1;
		to_p.y = to_f.y;
		render_moves(to_p, to_f, info);
	}
	else if (info->map[to_f.y][to_f.x - 1] == 'E' && info->coins <= 0)
	{
		info->moves_count++;
		mini_printf(info->moves_count, NULL);
		mini_printf(1, GREEN"You Won"RESET);
		close_window(info, EXIT_SUCCESS);
	}
}
