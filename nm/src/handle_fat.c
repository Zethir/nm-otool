/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 19:31:41 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/24 14:13:04 by cboussau         ###   ########.fr       */
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

char			*get_cpu_type(int cpu_type)
{
	if (cpu_type == CPU_TYPE_MC680x0)
		return ("m68k");
	else if (cpu_type == CPU_TYPE_I386)
		return ("i386");
	else if (cpu_type == CPU_TYPE_X86_64)
		return ("x86_64");
	else if (cpu_type == CPU_TYPE_ARM)
		return ("arm");
	else if (cpu_type == CPU_TYPE_ARM64)
		return ("arm64");
	else if (cpu_type == CPU_TYPE_MC88000)
		return ("m88k");
	else if (cpu_type == CPU_TYPE_I860)
		return ("i860");
	else if (cpu_type == CPU_TYPE_POWERPC)
		return ("ppc");
	else
		return (NULL);
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
