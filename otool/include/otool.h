/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:11:28 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/17 15:49:00 by cboussau         ###   ########.fr       */
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

void				print_binary(char *bin);
void				handle_32(char *file, void *end);
void				handle_64(char *file, void *end);
void				handle_ar(char *file, char *bin, void *end);
void				handle_fat(char *file, char *bin, void *end);
void				print_obj_path(char *bin, char *ar_name);
void				print_hexa(long long value, int len);
void				print_2_hexa(long long value);

int					check_filetype(char *file, char *bin, void *end);
int					nm_error_arg(char *str);
int					print_open_error(char *str);
int					print_fstat_error(char *str);
int					print_msg(char *str);

#endif
