/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 18:44:31 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/13 14:41:50 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static char	get_sort_opt(t_opt *opt)
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
	t_data	*data_tmp;

	if (check_rules(opt, 'U') && check_rules(opt, 'u'))
		return ;
	data_tmp = sort_data(data, get_sort_opt(opt));
	while (data_tmp)
	{
		if (ft_strcmp(data_tmp->name, "") && data_tmp->type != 'u')
		{
			if (check_rules(opt, 'U') && data_tmp->type == 'U')
				data_tmp = data_tmp->next;
			else if (check_rules(opt, 'u') && data_tmp->type != 'U')
				data_tmp = data_tmp->next;
			else
			{
				print_symbols(opt, data_tmp);
				data_tmp = data_tmp->next;
			}
		}
		else
			data_tmp = data_tmp->next;
	}
}
