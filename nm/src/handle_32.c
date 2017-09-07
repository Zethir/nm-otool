/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:11:56 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/07 21:15:02 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

void	print_output_32(int nsyms, int symoff, int stroff, char *file)
{
	int						i;
	char					*stringtable;
	struct nlist			*array;

	array = (void *)file + symoff;
	stringtable = (void *)file + stroff;
	i = 0;
	while (i < nsyms)
	{
		printf("%s\n", stringtable + array[i].n_un.n_strx);
		i++;
	}
}

void	handle_32(char *file, t_data **data)
{
	int						ncmds;
	int						i;
	struct mach_header		*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	header = (struct mach_header *)file;
	ncmds = header->ncmds;
	lc = (void *)file + sizeof(*header);
	i = 0;
	data = NULL;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			print_output_32(sym->nsyms, sym->symoff, sym->stroff, file);
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}
