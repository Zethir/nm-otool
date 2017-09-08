/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:46:17 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/07 22:48:58 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_convert(unsigned long long nb, char *s,
					unsigned long long base)
{
	unsigned long long	i;
	unsigned long long	j;
	const char			letter[16] = "0123456789abcdef";

	j = 0;
	i = 1;
	while (nb / i > base - 1)
		i = i * base;
	while (i != 0)
	{
		s[j] = letter[nb / i];
		nb = nb % i;
		i = i / base;
		j++;
	}
	s[j] = '\0';
	return (s);
}

char			*ft_itoa_base_uns(unsigned long long value,
					unsigned long long base)
{
	unsigned long long	i;
	unsigned long long	count;
	char				*s;

	count = 0;
	i = value;
	while (i > 0)
	{
		count++;
		i = i / base;
	}
	s = (char *)malloc(sizeof(char) * (count + 1));
	s = ft_convert(value, s, base);
	return (s);
}
