/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:31:42 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/09 20:33:51 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

t_data		*init_data(void)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	data->hexa = NULL;
	data->name = NULL;
	data->next = NULL;
	return (data);
}

void		push_data(t_data **head, t_data *data)
{
	t_data	*tmp;

	if (*head == NULL)
	{
		*head = data;
		return ;
	}
	else
		tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = data;
}
