/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:29:22 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/07 18:34:25 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

t_opt		*init_opt()
{
	t_opt	*opt;

	if (!(opt = (t_opt *)malloc(sizeof(t_opt))))
		return (NULL);
	opt->next = NULL;
	return (opt);
}

void	push_opt(t_opt **head, t_opt *opt)
{
	t_opt	*tmp;

	if (*head == NULL)
	{
		*head = opt;
		return ;
	}
	else
		tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = opt;
}

void	push_arg(t_arg **head, t_arg *arg)
{
	t_arg	*tmp;

	if (*head == NULL)
	{
		*head = arg;
		return ;
	}
	else
		tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = arg;
}

t_arg		*init_arg()
{
	t_arg	*arg;

	if (!(arg = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	arg->bin = NULL;
	arg->next = NULL;
	return (arg);
}
