/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sect_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 16:58:44 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/09 20:38:47 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

t_sect		*init_sect(void)
{
	t_sect	*sect;

	if (!(sect = (t_sect *)malloc(sizeof(t_sect))))
		return (NULL);
	sect->sectname = NULL;
	sect->nb_sect = 0;
	sect->next = NULL;
	return (sect);
}

void		push_sect(t_sect **head, t_sect *sect)
{
	t_sect	*tmp;

	if (*head == NULL)
	{
		*head = sect;
		return ;
	}
	else
		tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = sect;
}
