/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wipespace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:44:06 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/22 18:47:24 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wipespace(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	j = i;
	while (str[j] && !ft_isspace(str[j]))
		j++;
	res = ft_strsub(str, i, j - i);
	return (res);
}
