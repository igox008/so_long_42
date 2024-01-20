/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:17:53 by alaassir          #+#    #+#             */
/*   Updated: 2023/11/05 01:16:08 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (!len || s_len <= start)
		return (ft_strdup(""));
	if (start + len <= s_len)
		sub = (char *)malloc(len + 1);
	else
		sub = (char *)malloc(s_len - start + 1);
	if (sub == NULL)
		return (NULL);
	while (start + i < s_len && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
