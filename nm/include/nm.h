/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:11:28 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/19 18:12:55 by cboussau         ###   ########.fr       */
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
# include <ar.h>

# define OPT "uUrjp"

typedef struct		s_sect
{
	char			*sectname;
	int				nb_sect;
	struct s_sect	*next;
}					t_sect;

typedef struct		s_data
{
	char			*hexa;
	char			type;
	char			*name;
	struct s_data	*next;
}					t_data;

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

typedef struct		s_hub
{
	struct s_data	*data;
	struct s_opt	*opt;
}					t_hub;

t_opt				*init_opt(void);
t_arg				*init_arg(void);
t_data				*init_data(void);
t_sect				*init_sect(void);
t_arg				*save_options(t_opt **head, char **argv);

void				push_opt(t_opt **head, t_opt *opt);
void				push_arg(t_arg **head, t_arg *arg);
void				push_data(t_data **head, t_data *data, t_opt *opt);
void				push_sect(t_sect **head, t_sect *sect);
void				free_opt(t_opt *opt);
void				free_arg(t_arg *arg);
void				free_data(t_data *data);
void				free_sect(t_sect *sect);
void				print_binary(char *bin);
void				handle_32(char *file, t_hub *hub, void *end);
void				handle_64(char *file, t_hub *hub, void *end);
void				handle_ar(char *file, char *bin, t_hub *hub, void *end);
void				handle_fat(char *file, char *bin, t_hub *hub, void *end);
void				print_data(t_data *data, t_opt *opt);
void				print_obj_path(char *bin, char *ar_name);

int					check_filetype(char *file, char *bin, t_hub *hub, void *e);
int					nm_error_arg(char *str);
int					print_open_error(char *str);
int					print_fstat_error(char *str);
int					print_msg(char *str);

char				get_type(int n_type, int n_sect, int n_value, t_sect *sect);
char				get_sort_opt(t_opt *opt);
char				*get_hexa(long long value, char c, int len);

#endif
