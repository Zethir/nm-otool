/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:52:49 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/07 19:32:10 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

int		nm_error_arg(char *str)
{
	ft_putstr("ft_nm: Unknown command line argument '");
	ft_putstr(str);
	ft_putstr("'.\n");
	return (-1);
}

int		print_open_error(char *str)
{
	ft_putstr("ft_nm: ");
	ft_putstr(str);
	ft_putstr(": No such file or directory.\n");
	return (-1);
}

int		print_fstat_error(char *str)
{
	ft_putstr("ft_nm: ");
	ft_putstr(str);
	ft_putstr(": fstat() failed.\n");
	return (-1);
}

int		print_msg(char *str)
{
	ft_putstr(str);
	return (-1);
}

void	print_binary(char *bin)
{
	ft_putchar('\n');
	ft_putstr(bin);
	ft_putstr(":\n");
}
