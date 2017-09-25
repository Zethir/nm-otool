/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:32:43 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/25 14:12:11 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

uint32_t	is_swap_64_32(t_hub *hub, uint32_t ncmds)
{
	if (hub->magic == MH_CIGAM_64)
		return (swap_uint32(ncmds));
	else
		return (ncmds);
}

uint64_t	is_swap_64_64(t_hub *hub, uint64_t ncmds)
{
	if (hub->magic == MH_CIGAM_64)
		return (swap_uint64(ncmds));
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

uint32_t	swap_uint32(uint32_t num)
{
	uint32_t			swapped;

	swapped = ((num >> 24) & 0x000000FF) |
		((num << 8) & 0x00FF0000) |
		((num >> 8) & 0x0000FF00) |
		((num << 24) & 0xFF000000);
	return (swapped);
}

uint64_t	swap_uint64(uint64_t x)
{
	x = (x & 0x00000000FFFFFFFF) << 32 | (x & 0xFFFFFFFF00000000) >> 32;
	x = (x & 0x0000FFFF0000FFFF) << 16 | (x & 0xFFFF0000FFFF0000) >> 16;
	x = (x & 0x00FF00FF00FF00FF) << 8 | (x & 0xFF00FF00FF00FF00) >> 8;
	return (x);
}
