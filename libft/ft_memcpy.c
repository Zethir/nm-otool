/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:48:22 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/12 09:38:42 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*s2;

	i = 0;
	d1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	while (i < n)
	{
		d1[i] = s2[i];
		i++;
	}
	return (dst);
}
