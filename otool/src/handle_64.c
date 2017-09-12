/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:54:34 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/12 17:43:43 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

void		print_2_hexa(long long value)
{
	char	*hexa;
	char	*tmp;

	hexa = ft_strdup("00");
	tmp = ft_itoa_base_uns(value, 16);
	ft_strrcpy(hexa, tmp);
	free(tmp);
	ft_putstr(hexa);
	ft_putchar(' ');
	free(hexa);
}

static void	display_section_64(struct section_64 *sec, char *file)
{
	size_t			j;
	size_t			k;
	size_t			l;
	unsigned char	*offset;

	j = 0;
	l = 16;
	offset = (unsigned char*)file + sec->offset;
	while (j < sec->size)
	{
		k = j - 1;
		print_hexa(sec->addr + j, 16);
		while (++k < l && k < sec->size)
			print_2_hexa(offset[k]);
		ft_putchar('\n');
		j += 16;
		l += 16;
	}
}

static void	segment_64(struct segment_command_64 *sg, char *file)
{
	struct section_64	*sec;
	unsigned int		i;

	i = 0;
	sec = (struct section_64 *)((void *)sg + sizeof(struct segment_command_64));
	while (i < sg->nsects)
	{
		if (!ft_strcmp(sec[i].sectname, SECT_TEXT) &&
				!ft_strcmp(sec[i].segname, SEG_TEXT))
		{
			ft_putstr("Contents of (");
			ft_putstr(SEG_TEXT);
			ft_putchar(',');
			ft_putstr(SECT_TEXT);
			ft_putstr(") section\n");
			display_section_64(sec + i, file);
		}
		i++;
	}
}

void		handle_64(char *file)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	uint32_t				i;

	header = (struct mach_header_64 *)file;
	lc = (void *)file + sizeof(*header);
	i = 0;
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
			segment_64((struct segment_command_64 *)lc, file);
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}