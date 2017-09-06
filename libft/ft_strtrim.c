/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:26:36 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/12 11:01:39 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (ft_isspace(s[i]) == 1)
		i++;
	while (s[j])
	{
		if (ft_isspace(s[j]) == 0)
		{
			j++;
			len = j;
		}
		else
			j++;
	}
	if (len == 0)
		return (ft_strdup(""));
	return (ft_strsub(s, i, len - i));
}
