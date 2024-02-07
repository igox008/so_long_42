/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:08:05 by alaassir          #+#    #+#             */
/*   Updated: 2023/11/01 10:12:36 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_strlen(s1);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i <= len)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
