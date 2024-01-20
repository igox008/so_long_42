/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:37:22 by alaassir          #+#    #+#             */
/*   Updated: 2023/11/03 01:59:22 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		t;
	char	*new;

	i = 0;
	t = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1);
	while (is_set(s1[i], set) == 1 && s1[i])
		i++;
	if (s1[i] != '\0')
		while (is_set(s1[j - 1], set) == 1)
			j--;
	new = (char *)malloc(j - i + 1);
	if (new == NULL)
		return (NULL);
	while (i + t < j)
	{
		new[t] = s1[i + t];
		t++;
	}
	new[t] = '\0';
	return (new);
}
