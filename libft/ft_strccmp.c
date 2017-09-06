/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:48:32 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/30 17:48:48 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strccmp(const char *s1, const char *s2, char c)
{
	unsigned char *tmp1;
	unsigned char *tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (*tmp1 && *tmp1 == *tmp2 && *tmp1 != c)
	{
		tmp1++;
		tmp2++;
	}
	return (*tmp1 - *tmp2);
}
