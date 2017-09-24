/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 19:31:41 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/24 18:01:18 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

uint32_t		swap_uint32(uint32_t num)
{
	uint32_t	swapped;

	swapped = ((num >> 24) & 0x000000FF) |
		((num << 8) & 0x00FF0000) |
		((num >> 8) & 0x0000FF00) |
		((num << 24) & 0xFF000000);
	return (swapped);
}

uint64_t		swap_uint64(uint64_t x)
{
	x = (x & 0x00000000FFFFFFFF) << 32 | (x & 0xFFFFFFFF00000000) >> 32;
	x = (x & 0x0000FFFF0000FFFF) << 16 | (x & 0xFFFF0000FFFF0000) >> 16;
	x = (x & 0x00FF00FF00FF00FF) << 8 | (x & 0xFF00FF00FF00FF00) >> 8;
	return (x);
}

static void		print_arch(char *bin, char *ar_name)
{
	ft_putchar('\n');
	ft_putstr(bin);
	ft_putstr(" (for architecture ");
	ft_putstr(ar_name);
	ft_putstr("):\n");
}

static uint32_t	is_swap_fat(t_hub *hub, uint32_t ncmds)
{
	if (hub->magic == FAT_CIGAM)
		return (swap_uint32(ncmds));
	else
		return (ncmds);
}

void			handle_fat(char *file, char *bin, t_hub *hub)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	char				*cputype;
	uint32_t			i;
	int					magic;

	header = (void *)file;
	arch = (struct fat_arch *)(header + 1);
	i = 0;
	while (i < is_swap_fat(hub, header->nfat_arch))
	{
		if ((cputype = get_cpu_type(is_swap_fat(hub, arch[i].cputype))))
		{
			print_arch(bin, cputype);
			magic = hub->magic;
			check_filetype(file + is_swap_fat(hub, arch[i].offset), bin, hub);
			hub->magic = magic;
		}
		i++;
	}
}
