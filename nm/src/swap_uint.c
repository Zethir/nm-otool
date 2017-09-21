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

#include <nm.h>

uint32_t	is_swap_64_32(t_hub *hub, uint32_t ncmds)
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

uint64_t	is_swap_64_64(t_hub *hub, uint64_t ncmds)
{
	if (hub->magic == MH_CIGAM_64)
		return (swap_uint64(ncmds));
	else
		return (ncmds);
}
