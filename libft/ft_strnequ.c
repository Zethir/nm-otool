/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:24:21 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/12 10:57:14 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	size_t	cmp;

	i = 0;
	cmp = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] == s2[i])
			cmp++;
		i++;
	}
	if (cmp == i)
		return (1);
	return (0);
}
