/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 17:30:19 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/24 17:32:49 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

void	sort_alpha_loop(t_data *data, t_data *tmp)
{
	t_data	*tmp2;

	while (tmp->next)
	{
		if ((ft_strcmp(data->name, tmp->next->name) > 0) || (!ft_strcmp(
	data->name, tmp->next->name) && ft_strcmp(data->hexa, tmp->next->hexa)))
			tmp = tmp->next;
		else
		{
			tmp2 = tmp->next;
			tmp->next = data;
			data->next = tmp2;
			return ;
		}
	}
	tmp->next = data;
}

void	sort_reverse_loop(t_data *data, t_data *tmp)
{
	t_data	*tmp2;

	while (tmp->next)
	{
		if ((ft_strcmp(tmp->next->name, data->name) > 0) || (!ft_strcmp(
	data->name, tmp->next->name) && ft_strcmp(tmp->next->hexa, data->hexa)))
			tmp = tmp->next;
		else
		{
			tmp2 = tmp->next;
			tmp->next = data;
			data->next = tmp2;
			return ;
		}
	}
	tmp->next = data;
}
