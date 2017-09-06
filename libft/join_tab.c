/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:06:27 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/08 15:07:36 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_tab(char **arg)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp2 = ft_strdup(arg[0]);
	i = 1;
	while (arg[i])
	{
		tmp = ft_strjoin(tmp2, " ");
		free(tmp2);
		tmp2 = ft_strjoin(tmp, arg[i]);
		free(tmp);
		i++;
	}
	return (tmp2);
}
