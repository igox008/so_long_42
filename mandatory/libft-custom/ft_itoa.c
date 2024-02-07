/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 04:39:57 by alaassir          #+#    #+#             */
/*   Updated: 2024/01/11 00:28:34 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		if (n == 0)
			return (i);
		n *= -1;
	}
	while (n % 10 >= 0 && n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*num;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = n_len(n);
	num = (char *)malloc(len + 1);
	if (num == NULL)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		num[0] = '-';
		i = 1;
	}
	num[len] = '\0';
	while (len - 1 >= i)
	{
		num[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (num);
}
