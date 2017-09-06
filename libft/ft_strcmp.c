/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:40:36 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/12 10:50:40 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *temp1;
	unsigned char *temp2;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	while (*temp1 && *temp1 == *temp2)
	{
		temp1++;
		temp2++;
	}
	return (*temp1 - *temp2);
}
