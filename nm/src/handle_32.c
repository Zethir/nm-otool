/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:16:07 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/21 18:50:26 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static void		add_node_32(unsigned long n_value, char *str, t_hub *hub,
		char c)
{
	t_data	*tmp;

	tmp = init_data();
	tmp->hexa = get_hexa(n_value, c, 8);
	tmp->type = c;
	tmp->name = ft_strdup(str);
	push_data(&hub->data, tmp, hub->opt);
}

static void		store_data(struct symtab_command *sym, char *file,
			t_hub *hub, t_sect *sect)
{
	struct nlist			*nlist;
	char					*str;
	uint32_t				i;
	char					c;

	nlist = (void *)file + is_swap_32(hub, sym->symoff);
	if ((uint32_t)nlist > is_swap_32(hub, (uint32_t)hub->end))
		print_error_file();
	str = (void *)file + is_swap_32(hub, sym->stroff);
	i = 0;
	while (i < is_swap_32(hub, sym->nsyms))
	{
		if ((void *)str + is_swap_32(hub, nlist[i].n_un.n_strx) > hub->end)
			print_error_file();
		if ((c = get_type(nlist[i].n_type, nlist[i].n_sect,
				is_swap_32(hub, nlist[i].n_value), sect)) != ' ')
		{
			add_node_32(is_swap_32(hub, nlist[i].n_value), str +
					is_swap_32(hub, nlist[i].n_un.n_strx), hub, c);
		}
		i++;
	}
}

static void		segment_32(struct segment_command *sg, t_sect **sect,
		int *nb_sect, t_hub *hub)
{
	struct section		*sec;
	t_sect				*tmp;
	unsigned int		i;
	int					nb;

	i = 0;
	sec = (struct section *)((void *)sg + sizeof(struct segment_command));
	if ((uint32_t)sec > is_swap_32(hub, (uint32_t)hub->end))
		print_error_file();
	nb = *nb_sect;
	while (i < is_swap_32(hub, sg->nsects))
	{
		tmp = init_sect();
		tmp->sectname = ft_strdup((sec + i)->sectname);
		tmp->nb_sect = ++nb;
		push_sect(sect, tmp);
		i++;
	}
	*nb_sect = nb;
}

void			handle_32(char *file, t_hub *hub)
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
	while (i++ < is_swap_32(hub, header->ncmds))
	{
		if ((uint32_t)lc > is_swap_32(hub, (uint32_t)hub->end))
			print_error_file();
		if (is_swap_32(hub, lc->cmd) == LC_SEGMENT)
			segment_32((struct segment_command *)lc, &sect, &nb_sect, hub);
		if (is_swap_32(hub, lc->cmd) == LC_SYMTAB)
			store_data((struct symtab_command *)lc, file, hub, sect);
		lc = (void *)lc + is_swap_32(hub, lc->cmdsize);
	}
	free_sect(sect);
}
