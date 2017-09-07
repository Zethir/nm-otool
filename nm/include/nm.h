/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:11:28 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/07 19:26:52 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <libft.h>
# include <fcntl.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>

# define OPT "uUrgj"

typedef struct		s_opt
{
	char			c;
	struct s_opt	*next;
}					t_opt;

typedef struct		s_arg
{
	char			*bin;
	struct s_arg	*next;
}					t_arg;

t_opt				*init_opt();
t_arg				*init_arg();
t_arg				*save_options(t_opt **head, char **argv);

void				push_opt(t_opt **head, t_opt *opt);
void				push_arg(t_arg **head, t_arg *arg);
void				free_arg(t_arg *arg);
void				free_opt(t_opt *opt);
void				print_binary(char *bin);

int					nm_error_arg(char *str);
int					print_open_error(char *str);
int					print_fstat_error(char *str);
int					print_msg(char *str);

#endif
