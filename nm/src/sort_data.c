/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 19:16:53 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/09 20:03:02 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static void		swap_data(t_data *before, t_data *after)
{
	char	*hexa;
	char	type;
	char	*name;

	hexa = before->hexa;
	type = before->type;
	name = before->name;
	before->hexa = after->hexa;
	before->type = after->type;
	before->name = after->name;
	after->hexa = hexa;
	after->type = type;
	after->name = name;
}

static t_data	*reverse_data(t_data *data)
{
	t_data	*tmp;

	tmp = data;
	while (data && data->next)
	{
		if (ft_strcmp(data->next->name, data->name) > 0)
		{
			swap_data(data, data->next);
			data = tmp;
		}
		else if (!ft_strcmp(data->name, data->next->name) &&
					ft_strcmp(data->next->hexa, data->hexa) > 0)
		{
			swap_data(data, data->next);
			data = tmp;
		}
		else
			data = data->next;
	}
	return (tmp);
}

static t_data	*sort_alpha(t_data *data)
{
	t_data	*tmp;

	tmp = data;
	while (data && data->next)
	{
		if (ft_strcmp(data->name, data->next->name) > 0)
		{
			swap_data(data, data->next);
			data = tmp;
		}
		else if (!ft_strcmp(data->name, data->next->name) &&
					ft_strcmp(data->hexa, data->next->hexa) > 0)
		{
			swap_data(data, data->next);
			data = tmp;
		}
		else
			data = data->next;
	}
	return (tmp);
}

t_data			*sort_data(t_data *data, char c)
{
	if (c == 'p')
		return (data);
	else if (c == 'r')
		return (reverse_data(data));
	else
		return (sort_alpha(data));
}
