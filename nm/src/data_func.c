/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:31:42 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/24 17:34:41 by cboussau         ###   ########.fr       */
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

static void	add_to_list(t_data **head, t_data *data)
{
	t_data	*tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = data;
}

static void	sort_alpha(t_data **head, t_data *data)
{
	t_data	*tmp;
	t_data	*tmp2;

	tmp = *head;
	if (ft_strcmp(tmp->name, data->name) > 0)
	{
		tmp2 = tmp;
		*head = data;
		data->next = tmp2;
		return ;
	}
	if (!ft_strcmp(data->name, tmp->name) && ft_strcmp(tmp->hexa, data->hexa))
	{
		tmp2 = tmp;
		*head = data;
		data->next = tmp2;
		return ;
	}
	sort_alpha_loop(data, tmp);
}

static void	reverse_data(t_data **head, t_data *data)
{
	t_data	*tmp;
	t_data	*tmp2;

	tmp = *head;
	if (ft_strcmp(data->name, tmp->name) > 0)
	{
		tmp2 = tmp;
		*head = data;
		data->next = tmp2;
		return ;
	}
	if (!ft_strcmp(data->name, tmp->name) && ft_strcmp(data->hexa, tmp->hexa))
	{
		tmp2 = tmp;
		*head = data;
		data->next = tmp2;
		return ;
	}
	sort_reverse_loop(data, tmp);
}

void		push_data(t_data **head, t_data *data, t_opt *opt)
{
	char	c;

	c = 0;
	if (*head == NULL)
	{
		*head = data;
		return ;
	}
	else
	{
		if ((c = get_sort_opt(opt)) == 'r')
			reverse_data(head, data);
		else if (c == 'p')
			add_to_list(head, data);
		else
			sort_alpha(head, data);
	}
}
