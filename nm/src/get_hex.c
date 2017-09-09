/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:31:42 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/07 21:34:27 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

char	*get_hexa(unsigned long long value, int len)
{
	char	*hexa;
	char	*tmp;

	hexa = NULL;
	tmp = NULL;
	if (value == 0)
	{
		if (len == 8)
			hexa = ft_strdup("        ");
		else
			hexa = ft_strdup("                ");
		return (hexa);
	}
	else
	{
		if (len == 8)
			hexa = ft_strdup("00000000");
		else
			hexa = ft_strdup("0000000000000000");
		tmp = ft_itoa_base_uns(value, 16);
		ft_strrcpy(hexa, tmp);
		free(tmp);
		return (hexa);
	}
}
