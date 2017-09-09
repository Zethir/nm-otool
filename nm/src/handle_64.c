/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:16:07 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/09 20:35:57 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static void	store_data(struct symtab_command *sym, char *file,
			t_data **data, t_sect *sect)
{
	struct nlist_64			*nlist;
	t_data					*tmp;
	char					*stringtable;
	int						i;
	char					c;

	tmp = NULL;
	nlist = (void *)file + sym->symoff;
	stringtable = (void *)file + sym->stroff;
	i = 0;
	while (i < (int)sym->nsyms)
	{
		if ((c = get_type(nlist[i].n_type, nlist[i].n_sect,
						nlist[i].n_value, sect)) != ' ')
		{
			tmp = init_data();
			tmp->hexa = get_hexa(nlist[i].n_value, 16);
			tmp->type = c;
			tmp->name = ft_strdup(stringtable + nlist[i].n_un.n_strx);
			push_data(data, tmp);
		}
		i++;
	}
}

static void	segment_64(struct segment_command_64 *sg, t_sect **sect, int *nbsec)
{
	struct section_64	*sec;
	t_sect				*tmp;
	unsigned int		i;
	int					nb;

	i = 0;
	sec = (struct section_64 *)((void *)sg + sizeof(struct segment_command_64));
	nb = *nbsec;
	while (i < sg->nsects)
	{
		tmp = init_sect();
		tmp->sectname = ft_strdup((sec + i)->sectname);
		tmp->nb_sect = ++nb;
		push_sect(sect, tmp);
		i++;
	}
}

void		handle_64(char *file, t_data **data)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	t_sect					*sect;
	uint32_t				i;
	int						nb_sect;

	header = (struct mach_header_64 *)file;
	lc = (void *)file + sizeof(*header);
	sect = NULL;
	i = 0;
	nb_sect = 0;
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
			segment_64((struct segment_command_64 *)lc, &sect, &nb_sect);
		if (lc->cmd == LC_SYMTAB)
			store_data((struct symtab_command *)lc, file, data, sect);
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
	free_sect(sect);
}
