/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:32:43 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/21 18:49:36 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

uint32_t	is_swap_64(t_hub *hub, uint32_t ncmds)
{
	if (hub->magic == MH_CIGAM_64)
		return (swap_uint32(ncmds));
	else
		return (ncmds);
}

uint32_t	is_swap_32(t_hub *hub, uint32_t ncmds)
{
	if (hub->magic == MH_CIGAM)
		return (swap_uint32(ncmds));
	else
		return (ncmds);
}

uint32_t		swap_uint32(uint32_t num)
{
	uint32_t			swapped;

	swapped = ((num >> 24) & 0x000000FF) |
		((num << 8) & 0x00FF0000) |
		((num >> 8) & 0x0000FF00) |
		((num << 24) & 0xFF000000);
	return (swapped);
}
