/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:33:34 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/07 22:38:09 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrcpy(char *dst, const char *src)
{
	int	len_d;
	int	len_s;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	while (len_s > 0)
	{
		dst[len_d] = src[len_s];
		len_s--;
		len_d--;
	}
	return (dst);
}
