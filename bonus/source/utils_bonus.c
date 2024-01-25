/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:38:38 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/24 08:43:09 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	incr(int *arr, char c)
{
	if (c == '0')
		arr[0]++;
	else if (c == '1')
		arr[1]++;
	else if (c == 'C')
		arr[2]++;
	else if (c == 'E')
		arr[3]++;
	else if (c == 'P')
		arr[4]++;
}

t_boolean	a_o(char *first, char *last)
{
	size_t	i;

	i = 0;
	if (!first || !last)
		return (FALSE);
	while (first[i] && last[i])
	{
		if (first[i] != '1' || last[i] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_corr	get_xy(char **map, char c)
{
	size_t	i;
	size_t	j;
	t_corr	p;

	i = 0;
	p.x = 0;
	p.y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				p.x = j;
				p.y = i;
				return (p);
			}
			j++;
		}
		i++;
	}
	return (p);
}

t_corr	width_height(char **map)
{
	t_corr	max;
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (map[y])
		y++;
	while (map[0][x])
	{
		if (x > 127)
		{
			ft_putendl_fd(UNDERLINE RED"mlx cannot handle this map"RESET, 1);
			return (arr_fail(map, y), exit(0), max);
		}
		x++;
	}
	max.x = x;
	max.y = y;
	return (max);
}

char	*asset_getter(char	**map)
{
	static int	y;
	static int	x;
	static int	len;

	if (x == 0 && y == 0)
		len = ft_strlen(map[y]);
	if (x == len && ++y)
		x = 0;
	if (map[y])
	{
		if (map[y][x] == '1' && ++x)
			return (WALL);
		else if (map[y][x] == 'P' && ++x)
			return (P_R);
		else if (map[y][x] == 'C' && ++x)
			return (COIN);
		else if (map[y][x] == 'E' && ++x)
			return (EXIT_CLOSE);
		else if (map[y][x] == 'N' && ++x)
			return (ENEMY_OFF);
		else if (map[y][x] == '0' && ++x)
			return (NULL);
	}
	return (NULL);
}
