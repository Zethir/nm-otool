/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:56:45 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/04 19:08:21 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	int		i;
	int		len;
	char	**cpy;

	if (tab)
	{
		i = 0;
		len = ft_tablen(tab);
		if (!(cpy = (char **)malloc(sizeof(char *) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			cpy[i] = ft_strdup(tab[i]);
			i++;
		}
		cpy[i] = NULL;
		return (cpy);
	}
	return (NULL);
}
