/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:28:20 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/12 10:58:46 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *temp_s;

	temp_s = s;
	temp_s = temp_s + ft_strlen(s);
	while (*temp_s != (char)c && temp_s != s)
		temp_s--;
	if (*temp_s == (char)c)
		return ((char *)temp_s);
	else
		return (NULL);
}
