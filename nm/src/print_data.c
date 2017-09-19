/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 18:44:31 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/19 18:04:30 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

char		get_sort_opt(t_opt *opt)
{
	t_opt	*tmp;

	tmp = opt;
	while (tmp)
	{
		if (tmp->c == 'r' || tmp->c == 'p')
			return (tmp->c);
		tmp = tmp->next;
	}
	return (0);
}

static int	check_rules(t_opt *opt, char c)
{
	t_opt	*tmp;

	tmp = opt;
	while (tmp)
	{
		if (tmp->c == c)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	print_symbols(t_opt *opt, t_data *data)
{
	if (!check_rules(opt, 'j') && !check_rules(opt, 'u'))
	{
		ft_putstr(data->hexa);
		ft_putchar(' ');
		ft_putchar(data->type);
		ft_putchar(' ');
	}
	ft_putstr(data->name);
	ft_putchar('\n');
}

void		print_data(t_data *data, t_opt *opt)
{
	if (check_rules(opt, 'U') && check_rules(opt, 'u'))
		return ;
	while (data)
	{
		if (ft_strcmp(data->name, "") && data->type != 'u')
		{
			if (check_rules(opt, 'U') && data->type == 'U')
				data = data->next;
			else if (check_rules(opt, 'u') && data->type != 'U')
				data = data->next;
			else
			{
				print_symbols(opt, data);
				data = data->next;
			}
		}
		else
			data = data->next;
	}
}
