/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:44:50 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/07 21:12:09 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

void		free_arg(t_arg *arg)
{
	t_arg	*tmp;

	if (arg)
	{
		while (arg)
		{
			free(arg->bin);
			tmp = arg;
			arg = arg->next;
			free(tmp);
		}
		free(arg);
		arg = NULL;
	}
}

void		free_opt(t_opt *opt)
{
	t_opt	*tmp;

	if (opt)
	{
		while (opt)
		{
			tmp = opt;
			opt = opt->next;
			free(tmp);
		}
		free(opt);
		opt = NULL;
	}
}

void		free_data(t_data *data)
{
	t_data	*tmp;

	if (data)
	{
		while (data)
		{
			tmp = data;
			data = data->next;
			free(tmp);
		}
		free(data);
		data = NULL;
	}
}
