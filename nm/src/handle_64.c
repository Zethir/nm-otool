/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:16:07 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/07 23:07:39 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

char	*get_hexa(long long value, int len)
{
	char	*hexa;
	char	*tmp;

	hexa = NULL;
	tmp = NULL;
	if (value == 0)
	{
		if (len == 8)
			hexa = ft_strdup("        ");
		else
			hexa = ft_strdup("                ");
		return (hexa);
	}
	else
	{
		if (len == 8)
			hexa = ft_strdup("00000000");
		else
			hexa = ft_strdup("0000000000000000");
		tmp = ft_itoa_base_unsigned(value, 16);
		free(tmp);
		return (ft_strrcpy(hexa, tmp));	
	}
}

void	store_data(struct symtab_command *sym, char *file, t_data **data)
{
	struct nlist_64			*array;
	t_data					*tmp;
	char					*stringtable;
	int						i;
	
	tmp = NULL;
	array = (void *)file + sym->symoff;
	stringtable = (void *)file + sym->stroff;
	i = 0;
	while (i < (int)sym->nsyms)
	{
		tmp = init_data();
		tmp->hexa = get_hexa(array[i].n_value, 16);
		tmp->name = ft_strdup(stringtable + array[i].n_un.n_strx);
		push_data(data, tmp);
		i++;
	}
}

void	segment_32()
{
	;
}

void	handle_64(char *file, t_data **data)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	int						ncmds;
	int						i;

	
	header = (struct mach_header_64 *)file;
	ncmds = header->ncmds;
	lc = (void *)file + sizeof(*header);
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			segment_32();
		if (lc->cmd == LC_SYMTAB)
			store_data((struct symtab_command *)lc, file, data);
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}
