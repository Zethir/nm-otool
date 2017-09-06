/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:19:14 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/15 19:31:39 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d2;
	unsigned char	*s2;

	d2 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (d2 > s2)
	{
		while (len--)
			d2[len] = s2[len];
	}
	else
	{
		while (len--)
		{
			*d2 = *s2;
			d2++;
			s2++;
		}
	}
	return (dst);
}
