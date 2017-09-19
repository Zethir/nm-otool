/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:16:07 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/19 19:23:49 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static void	add_node_32(int n_value, char *str, t_hub *hub, char c)
{
	t_data	*tmp;

	tmp = init_data();
	tmp->hexa = get_hexa(n_value, c, 8);
	tmp->type = c;
	tmp->name = ft_strdup(str);
	push_data(&hub->data, tmp, hub->opt);
}

static void	store_data(struct symtab_command *sym, char *file,
			t_hub *hub, t_sect *sect)
{
	struct nlist			*nlist;
	char					*stringtable;
	int						i;
	char					c;

	nlist = (void *)file + sym->symoff;
	if (nlist > (struct nlist *)hub->end)
		print_error_file();
	stringtable = (void *)file + sym->stroff;
	i = 0;
	while (i < (int)sym->nsyms)
	{
		if ((void *)stringtable + nlist[i].n_un.n_strx > hub->end)
			print_error_file();
		if ((c = get_type(nlist[i].n_type, nlist[i].n_sect,
						nlist[i].n_value, sect)) != ' ')
		{
			add_node_32(nlist[i].n_value, stringtable + nlist[i].n_un.n_strx,
					hub, c);
		}
		i++;
	}
}

static void	segment_32(struct segment_command *sg, t_sect **sect, int *nb_sect,
		t_hub *hub)
{
	struct section		*sec;
	t_sect				*tmp;
	unsigned int		i;
	int					nb;

	i = 0;
	sec = (struct section *)((void *)sg + sizeof(struct segment_command));
	if (sec > (struct section *)hub->end)
		print_error_file();
	nb = *nb_sect;
	while (i < sg->nsects)
	{
		tmp = init_sect();
		tmp->sectname = ft_strdup((sec + i)->sectname);
		tmp->nb_sect = ++nb;
		push_sect(sect, tmp);
		i++;
	}
	*nb_sect = nb;
}

void		handle_32(char *file, t_hub *hub)
{
	struct mach_header		*header;
	struct load_command		*lc;
	t_sect					*sect;
	uint32_t				i;
	int						nb_sect;

	header = (struct mach_header *)file;
	lc = (void *)file + sizeof(*header);
	sect = NULL;
	i = 0;
	nb_sect = 0;
	while (i++ < header->ncmds)
	{
		if (lc > (struct load_command *)hub->end)
			print_error_file();
		if (lc->cmd == LC_SEGMENT)
			segment_32((struct segment_command *)lc, &sect, &nb_sect, hub);
		if (lc->cmd == LC_SYMTAB)
			store_data((struct symtab_command *)lc, file, hub, sect);
		lc = (void *)lc + lc->cmdsize;
	}
	free_sect(sect);
}
