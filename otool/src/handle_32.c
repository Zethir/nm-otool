/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:16:07 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/12 17:43:32 by cboussau         ###   ########.fr       */
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

static void	display_section_32(struct section *sec, char *file)
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
		print_hexa(sec->addr + j, 8);
		while (++k < l && k < sec->size)
			print_2_hexa(offset[k]);
		ft_putchar('\n');
		j += 16;
		l += 16;
	}
}

static void	segment_32(struct segment_command *sg, char *file)
{
	struct section		*sec;
	unsigned int		i;

	i = 0;
	sec = (struct section *)((void *)sg + sizeof(struct segment_command));
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
			display_section_32(sec + i, file);
		}
		i++;
	}
}

void		handle_32(char *file)
{
	struct mach_header		*header;
	struct load_command		*lc;
	uint32_t				i;

	header = (struct mach_header *)file;
	lc = (void *)file + sizeof(*header);
	i = 0;
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			segment_32((struct segment_command *)lc, file);
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}
