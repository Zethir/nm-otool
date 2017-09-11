/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 17:34:03 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/11 21:14:48 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static int	ar_size(char *ar_name)
{
	char	*size;

	size = ft_strchr(ar_name, '/');
	return (ft_atoi(size + 1));
}

void		print_obj_path(char *bin, char *ar_name)
{
	ft_putchar('\n');
	ft_putstr(bin);
	ft_putchar('(');
	ft_putstr(ar_name);
	ft_putstr("):\n");
}

void		handle_ar(char *file, char *bin, t_opt *opt)
{
	struct ar_hdr	*ar;
	struct ranlib	*ranlib;
	void			*obj;
	int				nb_obj;
	int				i;

	ar = (void *)file + SARMAG;
	nb_obj = *((int *)((void *)ar + sizeof(struct ar_hdr) +
				ar_size(ar->ar_name)));
	nb_obj /= sizeof(struct ranlib);
	ranlib = (void *)ar + sizeof(struct ar_hdr) + ar_size(ar->ar_name) + 4;
	i = 0;
	while (i < nb_obj)
	{
		ar = (void *)file + ranlib[i].ran_off;
		obj = (void *)ar + sizeof(struct ar_hdr) + ar_size(ar->ar_name);
		print_obj_path(bin, ar->ar_name + sizeof(struct ar_hdr));
		check_filetype(obj, bin, opt);
		i++;
	}
}
