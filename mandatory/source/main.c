/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:54:54 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/13 11:19:44 by alaassir         ###   ########.fr       */
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

int	mini_printf(int n, char *str)
{
	if (!str)
	{
		ft_putstr_fd("MOVE : ", 1);
		ft_putnbr_fd(n, 1);
		ft_putstr_fd("\n", 1);
	}
	else
	{
		while (str[n])
		{
			write(1, &str[n], 1);
			n++;
		}
		write(1, "\n", 1);
	}
	return (n);
}

char	**map_maker(char *str, size_t *last)
{
	int		fd;
	char	*line;
	char	*all;
	char	**map;
	int		i;

	all = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd(UNDERLINE RED"can't open the file"RESET, 1),
			NULL);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		all = ft_strjoin(all, line);
		if (*line == '\n' || i > 128)
			return (special_handler(i, all));
		ft_free(&line, 0, 0, 0);
		(*last)++;
		line = get_next_line(fd);
		i++;
	}
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
		if (!map)
			return (NULL);
		if (!map_chek(map, last))
			return (arr_fail(map, last),
				ft_putendl_fd(UNDERLINE RED"ERROR INVALID MAP"RESET, 1), NULL);
		if (!flood_fill_it(map, last))
			return (arr_fail(map, last),
				ft_putendl_fd(UNDERLINE RED"No way to win"RESET, 1), NULL);
	}
	else
		return (arr_fail(map, last),
			ft_putendl_fd(UNDERLINE RED"ERROR:\nWrong input"RESET, 1), NULL);
	return (map);
}
