/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:44:50 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/19 18:12:49 by cboussau         ###   ########.fr       */
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
			free(data->hexa);
			free(data->name);
			tmp = data;
			data = data->next;
			free(tmp);
		}
		free(data);
		data = NULL;
	}
}

void		free_sect(t_sect *sect)
{
	t_sect	*tmp;

	if (sect)
	{
		while (sect)
		{
			free(sect->sectname);
			tmp = sect;
			sect = sect->next;
			free(tmp);
		}
		free(sect);
		sect = NULL;
	}
}
