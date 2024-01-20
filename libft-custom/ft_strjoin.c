/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:09:54 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/13 09:35:14 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		t;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	t = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(t + 1);
	if (new == NULL)
		return (ft_free((char **)&s1, 0, 0, 0));
	while (j < ft_strlen(s1))
		new[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen(s2))
		new[i++] = s2[j++];
	new[i] = '\0';
	free((char *)s1);
	return (new);
}
