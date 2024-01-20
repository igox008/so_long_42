/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:54:54 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/19 08:45:07 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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

void	fill_animation_path(t_data **i)
{
	(*i)->anim_r[0] = "bonus/assets/animation/Walk0_right.xpm";
	(*i)->anim_r[1] = "bonus/assets/animation/Walk1_right.xpm";
	(*i)->anim_r[2] = "bonus/assets/animation/Walk2_right.xpm";
	(*i)->anim_r[3] = "bonus/assets/animation/Walk3_right.xpm";
	(*i)->anim_r[4] = "bonus/assets/animation/Walk4_right.xpm";
	(*i)->anim_r[5] = "bonus/assets/animation/Walk5_right.xpm";
	(*i)->anim_r[6] = "bonus/assets/animation/Walk6_right.xpm";
	(*i)->anim_r[7] = "bonus/assets/animation/Walk7_right.xpm";
	(*i)->anim_r[8] = "bonus/assets/animation/Walk0_left.xpm";
	(*i)->anim_r[9] = "bonus/assets/animation/Walk1_left.xpm";
	(*i)->anim_r[10] = "bonus/assets/animation/Walk2_left.xpm";
	(*i)->anim_r[11] = "bonus/assets/animation/Walk3_left.xpm";
	(*i)->anim_r[12] = "bonus/assets/animation/Walk4_left.xpm";
	(*i)->anim_r[13] = "bonus/assets/animation/Walk5_left.xpm";
	(*i)->anim_r[14] = "bonus/assets/animation/Walk6_left.xpm";
	(*i)->anim_r[15] = "bonus/assets/animation/Walk7_left.xpm";
	(*i)->anim_r[16] = "bonus/assets/animation/Idle_0.xpm";
	(*i)->anim_r[17] = "bonus/assets/animation/Idle_1.xpm";
	(*i)->anim_r[18] = "bonus/assets/animation/Idle_2.xpm";
	(*i)->anim_r[19] = "bonus/assets/animation/Idle_3.xpm";
	(*i)->anim_r[20] = "bonus/assets/animation/Idle_4.xpm";
	(*i)->anim_r[21] = "bonus/assets/animation/Idle_5.xpm";
	(*i)->anim_r[22] = NULL;
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

	(1 == 1) && (all = NULL, fd = open(str, O_RDONLY));
	if (fd == -1)
		return (ft_putendl_fd(UNDERLINE RED"can't open the file"RESET, 1),
			NULL);
	(1 == 1) && (line = get_next_line(fd), i = 0);
	while (line)
	{
		all = ft_strjoin(all, line);
		if (*line == '\n' || i > 128)
			return (free(line), special_handler(i, all));
		ft_free(&line, 0, 0, 0);
		(*last)++;
		line = get_next_line(fd);
		i++;
	}
	if (!check_last(all) && mini_printf(0, RED"invalid map"RESET))
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
