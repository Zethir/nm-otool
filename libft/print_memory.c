/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:40:32 by cboussau          #+#    #+#             */
/*   Updated: 2017/08/31 00:04:37 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_hexa(unsigned long addr)
{
	const char	*hex;

	hex = "0123456789abcdef";
	if (addr >= 16)
	{
		print_hexa(addr / 16);
		print_hexa(addr % 16);
	}
	else
		ft_putchar(hex[addr]);
}

void	print_memory(void *mem)
{
	ft_putstr("0x");
	print_hexa((unsigned long)mem);
}
