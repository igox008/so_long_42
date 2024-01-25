/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:08:20 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/25 19:55:07 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_boolean	check_ext(char *str)
{
	int	i;
	int	t;

	i = 0;
	t = ft_strlen(str);
	if (t <= 4)
		return (FALSE);
	while (str[i])
	{
		if (str[i] == '.')
			t = i;
		i++;
	}
	if (ft_strncmp(str + t, ".ber", t) == 0)
		return (TRUE);
	return (FALSE);
}

t_boolean	map_chek(char **str, int l)
{
	size_t		i;
	size_t		j;
	size_t		n;
	static int	c[5];

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '0' && str[i][j] != '1' && str[i][j] != 'C'
			&& str[i][j] != 'E' && str[i][j] != 'P')
				return (FALSE);
			incr(c, str[i][j]);
			j++;
		}
		if ((i > 0 && n != j) || (str[i][0] != '1' || str[i][j - 1] != '1'))
			return (FALSE);
		n = j;
		i++;
	}
	if (!c[2] || c[3] != 1 || c[4] != 1 || i < 3 || !a_o(str[0], str[l - 1]))
		return (FALSE);
	return (TRUE);
}
