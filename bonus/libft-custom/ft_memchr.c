/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:20:30 by alaassir          #+#    #+#             */
/*   Updated: 2023/11/06 21:18:01 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		uc;

	i = 0;
	str = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
