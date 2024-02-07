/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:28:46 by alaassir          #+#    #+#             */
/*   Updated: 2023/11/07 05:51:46 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*crnt;
	void	*tmp;

	head = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		tmp = f(lst->content);
		crnt = ft_lstnew(tmp);
		if (!crnt)
		{
			del(tmp);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, crnt);
		lst = lst->next;
	}
	return (head);
}
