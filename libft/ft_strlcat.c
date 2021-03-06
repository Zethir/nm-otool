/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:08:30 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/12 10:54:13 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*d;
	const char		*s;
	size_t			n;
	size_t			len_d;

	d = dst;
	s = src;
	n = size;
	while (n-- > 0 && *d)
		d++;
	len_d = d - dst;
	n = size - len_d;
	if (n == 0)
		return (len_d + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (len_d + (s - src));
}
