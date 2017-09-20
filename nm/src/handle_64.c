/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:16:07 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/20 16:13:26 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static void	add_node_64(unsigned long n_value, char *str, t_hub *hub, char c)
{
	t_data	*tmp;

	tmp = init_data();
	tmp->hexa = get_hexa(n_value, c, 16);
	tmp->type = c;
	tmp->name = ft_strdup(str);
	push_data(&hub->data, tmp, hub->opt);
}

static void	store_data(struct symtab_command *sym, char *file,
			t_hub *hub, t_sect *sect)
{
	struct nlist_64			*nlist;
	char					*stringtable;
	int						i;
	char					c;

	nlist = (void *)file + sym->symoff;
	if (nlist > (struct nlist_64 *)hub->end)
		print_error_file();
	stringtable = (void *)file + sym->stroff;
	i = 0;
	while (i < (int)sym->nsyms)
	{
		if ((void *)stringtable + nlist[i].n_un.n_strx > hub->end)
			print_error_file();
		if ((c = get_type(nlist[i].n_type, nlist[i].n_sect,
			nlist[i].n_value, sect)) != ' ' &&
				ft_strcmp(stringtable + nlist[i].n_un.n_strx, "radr://5614542"))
		{
			add_node_64(nlist[i].n_value, stringtable + nlist[i].n_un.n_strx,
					hub, c);
		}
		i++;
	}
}

static void	segment_64(struct segment_command_64 *sg, t_sect **sect, int *nbsec,
		t_hub *hub)
{
	struct section_64	*sec;
	t_sect				*tmp;
	unsigned int		i;
	int					nb;

	i = 0;
	sec = (struct section_64 *)((void *)sg + sizeof(struct segment_command_64));
	if (sec > (struct section_64 *)hub->end)
		print_error_file();
	nb = *nbsec;
	while (i < sg->nsects)
	{
		tmp = init_sect();
		tmp->sectname = ft_strdup((sec + i)->sectname);
		tmp->nb_sect = ++nb;
		push_sect(sect, tmp);
		i++;
	}
	*nbsec = nb;
}

void		handle_64(char *file, t_hub *hub)
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
	while (i++ < header->ncmds)
	{
		if (lc > (struct load_command *)hub->end)
			print_error_file();
		if (lc->cmd == LC_SEGMENT_64)
			segment_64((struct segment_command_64 *)lc, &sect, &nb_sect, hub);
		if (lc->cmd == LC_SYMTAB)
			store_data((struct symtab_command *)lc, file, hub, sect);
		lc = (void *)lc + lc->cmdsize;
	}
	free_sect(sect);
}
