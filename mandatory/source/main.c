/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:54:54 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/26 21:58:26 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	coin_count(char **map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	mini_printf(int fd, char *str)
{
	int	n;

	n = 0;
	if (!str)
	{
		n = fd;
		ft_putstr_fd("MOVE : ", 1);
		ft_putnbr_fd(n, 1);
		ft_putstr_fd("\n", 1);
	}
	else
		ft_putendl_fd(str, fd);
	return (0);
}

t_boolean	check_last(char *all)
{
	int	i;

	if (!all)
		return (FALSE);
	i = ft_strlen(all);
	if (i > 0)
		i--;
	if (all[i] == '\n')
		return (FALSE);
	return (TRUE);
}

char	**map_maker(char *str, size_t *last)
{
	int		fd;
	char	*line;
	char	*all;
	char	**map;
	int		i;

	fd = open(str, O_RDONLY);
	if (fd == -1 && mini_printf(0, RED"cannot open this file"RESET))
		return (NULL);
	(1) && (all = NULL, line = get_next_line(fd), i = 0);
	while (line)
	{
		all = ft_strjoin(all, line);
		if (*line == '\n' || i > 128)
			return (free(line), special_handler(i, all));
		ft_free(&line, 0, 0, 0);
		(1) && ((*last)++, i++);
		line = get_next_line(fd);
	}
	if (!check_last(all) && mini_printf(0, RED"map error"RESET))
		return (free(all), NULL);
	if (close(fd) != 0)
		return (free(all), NULL);
	map = ft_split(all, '\n');
	return (free(all), all = NULL, map);
}

char	**parse_main(int ac, char **av)
{
	char	**map;
	size_t	last;

	last = 0;
	map = NULL;
	if (ac == 2 && check_ext(av[1]) == TRUE)
	{
		map = map_maker(av[1], &last);
		if (!map && !mini_printf(2, RED"map error"RESET))
			return (NULL);
		if (!map_chek(map, last))
			return (arr_fail(map, last),
				ft_putendl_fd(UNDERLINE RED"ERROR INVALID MAP"RESET, 2), NULL);
		if (!flood_fill_it(map, last))
			return (arr_fail(map, last),
				ft_putendl_fd(UNDERLINE RED"No way to win"RESET, 2), NULL);
	}
	else
		return (arr_fail(map, last),
			ft_putendl_fd(UNDERLINE RED"ERROR:\nWrong input"RESET, 2), NULL);
	return (map);
}
