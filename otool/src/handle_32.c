/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:16:07 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/24 18:25:43 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

void		print_hexa(long long value, int len)
{
	char	*hexa;
	char	*tmp;

	if (len == 8)
		hexa = ft_strdup("00000000");
	else
		hexa = ft_strdup("0000000000000000");
	tmp = ft_itoa_base_uns(value, 16);
	ft_strrcpy(hexa, tmp);
	free(tmp);
	ft_putstr(hexa);
	ft_putchar('\t');
	free(hexa);
}

static void	display_section_32(struct section *sec, char *file, t_hub *hub)
{
	size_t			j;
	size_t			k;
	size_t			l;
	unsigned char	*offset;

	j = 0;
	l = 16;
	offset = (unsigned char*)file + is_swap_32(hub, sec->offset);
	while (j < is_swap_32(hub, sec->size))
	{
		k = j - 1;
		print_hexa(is_swap_32(hub, sec->addr + j), 8);
		while (++k < l && k < is_swap_32(hub, sec->size))
			print_2_hexa(offset[k]);
		ft_putchar('\n');
		j += 16;
		l += 16;
	}
}

static void	segment_32(struct segment_command *sg, char *file, t_hub *hub)
{
	struct section		*sec;
	unsigned int		i;

	i = 0;
	sec = (struct section *)((void *)sg + sizeof(struct segment_command));
	if ((uint32_t)sec > is_swap_32(hub, (uint32_t)hub->end))
		print_error_file();
	while (i < is_swap_32(hub, sg->nsects))
	{
		if (!ft_strcmp(sec[i].sectname, SECT_TEXT) &&
				!ft_strcmp(sec[i].segname, SEG_TEXT))
		{
			ft_putstr("Contents of (");
			ft_putstr(SEG_TEXT);
			ft_putchar(',');
			ft_putstr(SECT_TEXT);
			ft_putstr(") section\n");
			display_section_32(sec + i, file, hub);
		}
		i++;
	}
}

void		handle_32(char *file, t_hub *hub)
{
	struct mach_header		*header;
	struct load_command		*lc;
	uint32_t				i;

	header = (struct mach_header *)file;
	lc = (void *)file + sizeof(*header);
	i = 0;
	while (i < is_swap_32(hub, header->ncmds))
	{
		if ((uint32_t)lc > is_swap_32(hub, (uint32_t)hub->end))
			print_error_file();
		if (is_swap_32(hub, lc->cmd) == LC_SEGMENT)
			segment_32((struct segment_command *)lc, file, hub);
		lc = (void *)lc + is_swap_32(hub, lc->cmdsize);
		i++;
	}
}
