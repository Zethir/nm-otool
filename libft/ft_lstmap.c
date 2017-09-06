/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:34:21 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/12 09:35:45 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*new;

	new = f(lst);
	tmp = ft_lstnew(new->content, new->content_size);
	start = tmp;
	tmp2 = tmp;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		tmp = ft_lstnew(new->content, new->content_size);
		tmp2->next = tmp;
		lst = lst->next;
	}
	return (start);
}
