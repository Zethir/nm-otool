/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:47:59 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/12 10:53:51 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new != NULL)
	{
		ft_strcat(new, s1);
		ft_strcat(new, s2);
	}
	return (new);
}
