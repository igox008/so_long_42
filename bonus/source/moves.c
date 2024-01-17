/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:42:54 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/17 02:10:24 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_up(t_data **info)
{
	t_corr	to_p;
	t_corr	to_f;

	to_f = get_xy((*info)->map, 'P');
	if ((*info)->map[to_f.y - 1][to_f.x] == '0' ||
		(*info)->map[to_f.y - 1][to_f.x] == 'C')
	{
		to_p.x = to_f.x;
		to_p.y = to_f.y - 1;
		animate_idle(to_p, to_f, info);
		render_moves(to_p, to_f, (*info)->dir, &info);
	}
	else if ((*info)->map[to_f.y - 1][to_f.x] == 'E' && (*info)->coins <= 0)
		close_window(*info, EXIT_SUCCESS);
	else
		render_moves(to_f, to_f, (*info)->dir, &info);
	(*info)->keyp = -1;
}

void	move_down(t_data **info)
{
	t_corr	to_p;
	t_corr	to_f;

	to_f = get_xy((*info)->map, 'P');
	if ((*info)->map[to_f.y + 1][to_f.x] == '0' ||
		(*info)->map[to_f.y + 1][to_f.x] == 'C')
	{
		to_p.x = to_f.x;
		to_p.y = to_f.y + 1;
		animate_idle(to_p, to_f, info);
		render_moves(to_p, to_f, (*info)->dir, &info);
	}
	else if ((*info)->map[to_f.y + 1][to_f.x] == 'E' && (*info)->coins <= 0)
		close_window(*info, EXIT_SUCCESS);
	else
		render_moves(to_f, to_f, (*info)->dir, &info);
	(*info)->keyp = -1;
}

void	move_right(t_data **info)
{
	t_corr	to_p;
	t_corr	to_f;

	to_f = get_xy((*info)->map, 'P');
	if ((*info)->map[to_f.y][to_f.x + 1] == '0' ||
		(*info)->map[to_f.y][to_f.x + 1] == 'C')
	{
		to_p.x = to_f.x + 1;
		to_p.y = to_f.y;
		animate_right(to_p, to_f, info);
		render_moves(to_p, to_f, P_R, &info);
	}
	else if ((*info)->map[to_f.y][to_f.x + 1] == 'E' && (*info)->coins <= 0)
		close_window(*info, EXIT_SUCCESS);
	else
		render_moves(to_f, to_f, P_R, &info);
	(*info)->keyp = -1;
}

void	move_left(t_data **info)
{
	t_corr	to_p;
	t_corr	to_f;

	to_f = get_xy((*info)->map, 'P');
	if ((*info)->map[to_f.y][to_f.x - 1] == '0' ||
		(*info)->map[to_f.y][to_f.x - 1] == 'C')
	{
		to_p.x = to_f.x - 1;
		to_p.y = to_f.y;
		animate_left(to_p, to_f, info);
		render_moves(to_p, to_f, P_L, &info);
	}
	else if ((*info)->map[to_f.y][to_f.x - 1] == 'E' && (*info)->coins <= 0)
		close_window(*info, EXIT_SUCCESS);
	else
		render_moves(to_f, to_f, P_L, &info);
	(*info)->keyp = -1;
}
