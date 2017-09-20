/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:52:49 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/20 15:19:56 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

int		nm_error_arg(char *str)
{
	ft_putstr_fd("ft_nm: Unknown command line argument '", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("'.\n", 2);
	return (-1);
}

int		print_open_error(char *str)
{
	ft_putstr_fd("ft_nm: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory.\n", 2);
	return (-1);
}

int		print_fstat_error(char *str)
{
	ft_putstr_fd("ft_nm: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": fstat() failed.\n", 2);
	return (-1);
}

int		print_msg(char *str)
{
	ft_putstr_fd(str, 2);
	return (-1);
}

void	print_binary(char *bin)
{
	ft_putchar('\n');
	ft_putstr(bin);
	ft_putstr(":\n");
}
