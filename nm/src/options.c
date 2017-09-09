/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:47:48 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/09 20:37:21 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static void	option_loop(t_opt **head, char *options)
{
	t_opt	*opt;
	int		i;

	i = 1;
	while (options[i])
	{
		if (ft_strchr(OPT, options[i]))
		{
			opt = init_opt();
			opt->c = options[i];
			push_opt(head, opt);
		}
		else
		{
			nm_error_arg(options);
			free_opt(*head);
			exit(-1);
		}
		i++;
	}
}

static void	add_arg(t_arg **arg, char *str)
{
	t_arg	*tmp;

	tmp = init_arg();
	tmp->bin = ft_strdup(str);
	push_arg(arg, tmp);
}

t_arg		*save_options(t_opt **head, char **argv)
{
	t_arg	*arg;
	int		i;

	i = 1;
	arg = NULL;
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1])
			option_loop(head, argv[i]);
		else
			add_arg(&arg, argv[i]);
		i++;
	}
	return (arg);
}
