/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 06:15:42 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/18 00:29:22 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	enemy_dir(t_data *i)
{
	t_corr		c;

	c = get_xy(i->map, 'N');
	if (i->map[c.y][c.x + 1] != '1' && i->map[c.y][c.x + 1] != 'C' && i->map[c.y][c.x + 1] != 'E')
		return ('R');
	else if (i->map[c.y][c.x - 1] != '1' && i->map[c.y][c.x - 1] != 'C' && i->map[c.y][c.x - 1] != 'E')
		return ('L');
	else if (i->map[c.y + 1][c.x] != '1' && i->map[c.y + 1][c.x] != 'C' && i->map[c.y + 1][c.x] != 'E')
		return ('D');
	else if (i->map[c.y - 1][c.x] != '1' && i->map[c.y - 1][c.x] != 'C' && i->map[c.y - 1][c.x] != 'E')
		return ('U');
	return ('Z');
}

