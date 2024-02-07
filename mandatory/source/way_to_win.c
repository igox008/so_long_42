/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:51:27 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/11 00:19:33 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**arr_fail(char **array, size_t row)
{
	size_t	i;

	i = 0;
	while (i < row)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**copy_map(char **map, int last)
{
	char	**copy;
	size_t	i;

	i = 0;
	copy = (char **)malloc((last + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < (size_t)last)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (arr_fail(copy, i));
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

t_boolean	skip(char c)
{
	if (c == '1')
		return (TRUE);
	return (FALSE);
}

void	flood(char **map, size_t x, size_t y, size_t rows)
{
	size_t	len;

	len = ft_strlen(map[0]);
	if (x < 0 || x >= len || y < 0 || y >= rows || skip(map[y][x]))
		return ;
	else if (map[y][x] == 'E')
		map[y][x] = '1';
	else
	{
		map[y][x] = '1';
		flood(map, x, y + 1, rows);
		flood(map, x, y - 1, rows);
		flood(map, x + 1, y, rows);
		flood(map, x - 1, y, rows);
	}
}

t_boolean	flood_fill_it(char **map, size_t rows)
{
	char		**copy;
	t_corr		p;
	static int	check[5];
	size_t		i;
	size_t		j;

	p = get_xy(map, 'P');
	copy = copy_map(map, rows);
	if (!copy)
		return (FALSE);
	flood(copy, p.x, p.y, rows);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
			incr(check, copy[i][j++]);
		i++;
	}
	if (check[2] != 0 || check[3] != 0)
		return (arr_fail(copy, rows), FALSE);
	return (arr_fail(copy, rows), TRUE);
}
