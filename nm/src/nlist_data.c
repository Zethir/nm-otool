/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlist_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:31:42 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/09 20:36:31 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

char		*get_hexa(unsigned long long value, int len)
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
		tmp = ft_itoa_base_uns(value, 16);
		ft_strrcpy(hexa, tmp);
		free(tmp);
		return (hexa);
	}
}

static char	get_sect(t_sect *sect, int n_sect)
{
	t_sect	*tmp;
	char	c;

	tmp = sect;
	c = 's';
	while (tmp)
	{
		if (tmp->nb_sect == n_sect)
		{
			if (!ft_strcmp(tmp->sectname, SECT_DATA))
				c = 'd';
			else if (!ft_strcmp(tmp->sectname, SECT_TEXT))
				c = 't';
			else if (!ft_strcmp(tmp->sectname, SECT_BSS))
				c = 'b';
		}
		tmp = tmp->next;
	}
	return (c);
}

char		get_type(int n_type, int n_sect, int n_value, t_sect *sect)
{
	char	c;

	c = ' ';
	if ((n_type & N_TYPE) == N_UNDF)
	{
		c = 'u';
		if (n_value != 0)
			c = 'c';
	}
	else if ((n_type & N_TYPE) == N_ABS)
		c = 'a';
	else if ((n_type & N_TYPE) == N_SECT)
		c = get_sect(sect, n_sect);
	else if ((n_type & N_TYPE) == N_PBUD)
		c = 'u';
	else if ((n_type & N_TYPE) == N_INDR)
		c = 'i';
	if ((n_type & N_EXT) && c != ' ')
		c = ft_toupper(c);
	return (c);
}
