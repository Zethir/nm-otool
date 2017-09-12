/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 19:31:41 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/12 17:44:26 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

static uint32_t	swap_uint32(uint32_t num)
{
	uint32_t			swapped;

	swapped = ((num >> 24) & 0x000000FF) |
		((num << 8) & 0x00FF0000) |
		((num >> 8) & 0x0000FF00) |
		((num << 24) & 0xFF000000);
	return (swapped);
}

char			*get_cpu_type(int cpu_type)
{
	if (cpu_type == CPU_TYPE_MC680x0)
		return ("m68k");
	else if (cpu_type == CPU_TYPE_X86)
		return ("x86");
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
	else
		return (NULL);
}

void			handle_fat(char *file, char *bin)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	char				*cputype;
	uint32_t			i;

	header = (void *)file;
	arch = (struct fat_arch *)(header + 1);
	i = 0;
	while (i < swap_uint32(header->nfat_arch))
	{
		if ((cputype = get_cpu_type(swap_uint32(arch[i].cputype))))
		{
			print_obj_path(bin, cputype);
			check_filetype(file + swap_uint32(arch[i].offset), bin);
		}
		i++;
	}
}
