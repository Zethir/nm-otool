/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 19:31:41 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/24 17:50:58 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

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
	else if (cpu_type == CPU_TYPE_X86)
		return ("x86");
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
