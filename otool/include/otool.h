/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:11:28 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/24 18:22:54 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H

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

typedef struct		s_hub
{
	void			*end;
	uint32_t		magic;
}					t_hub;

void				print_binary(char *bin);
void				handle_32(char *file, t_hub *hub);
void				handle_64(char *file, t_hub *hub);
void				handle_ar(char *file, char *bin, t_hub *hub);
void				handle_fat(char *file, char *bin, t_hub *hub);
void				print_obj_path(char *bin, char *ar_name);
void				print_hexa(long long value, int len);
void				print_2_hexa(long long value);
void				print_error_file();

int					check_filetype(char *file, char *bin, t_hub *hub);
int					nm_error_arg(char *str);
int					print_open_error(char *str);
int					print_fstat_error(char *str);
int					print_msg(char *str);

uint32_t			is_swap_32(t_hub *hub, uint32_t ncmds);
uint32_t			is_swap_64_32(t_hub *hub, uint32_t ncmds);
uint64_t			is_swap_64_64(t_hub *hub, uint64_t ncmds);
uint32_t			swap_uint32(uint32_t num);
uint64_t			swap_uint64(uint64_t num);

#endif
