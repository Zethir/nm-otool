/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:30:07 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/24 17:25:14 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

int				check_filetype(char *file, char *bin, t_hub *hub)
{
	hub->magic = *(int *)file;
	if (hub->magic == MH_MAGIC || hub->magic == MH_CIGAM)
		handle_32(file, hub);
	else if (hub->magic == MH_MAGIC_64 || hub->magic == MH_CIGAM_64)
		handle_64(file, hub);
	else if (hub->magic == FAT_MAGIC || hub->magic == FAT_CIGAM)
		handle_fat(file, bin, hub);
	else if (!ft_strncmp(file, ARMAG, SARMAG))
		handle_ar(file, bin, hub);
	else
	{
		return (
			print_msg("The file wasn't recognized as a valid object file\n"));
	}
	print_data(hub->data, hub->opt);
	free_data(hub->data);
	hub->data = NULL;
	return (0);
}

static int		launch_nm(char *bin, t_hub *hub)
{
	char		*file;
	int			fd;
	struct stat stat;

	if ((fd = open(bin, O_RDONLY)) < 0)
		return (print_open_error(bin));
	if (fstat(fd, &stat) < 0)
		return (print_fstat_error(bin));
	if (stat.st_size == 0)
		return (print_msg("File is empty\n"));
	if ((stat.st_mode & S_IFMT) == S_IFDIR)
		return (print_msg("Can't read a directory\n"));
	if ((file = mmap(0, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
			== MAP_FAILED)
		return (print_msg("Can't MMAP on this fd\n"));
	hub->end = file + stat.st_size;
	if (check_filetype(file, bin, hub) < 0)
		return (-1);
	if (munmap(file, stat.st_size) < 0)
		return (print_msg("Can't MUNMAP this page\n"));
	if (close(fd) < 0)
		return (print_msg("Can't close this file descriptor\n"));
	return (0);
}

static int		get_arg_len(t_arg *arg)
{
	t_arg		*tmp;
	int			i;

	tmp = arg;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static void		arg_loop(t_arg *arg, t_hub *hub)
{
	int			i;

	i = get_arg_len(arg);
	while (arg)
	{
		if (i > 1)
			print_binary(arg->bin);
		if (launch_nm(arg->bin, hub) < 0)
			return ;
		arg = arg->next;
	}
}

int				main(int argc, char **argv)
{
	t_hub		*hub;
	t_arg		*arg;

	arg = NULL;
	if (!(hub = (t_hub *)malloc(sizeof(t_hub))))
		return (-1);
	hub->opt = NULL;
	hub->data = NULL;
	if (argc == 1)
		launch_nm("./a.out", hub);
	else
	{
		if ((arg = save_options(&hub->opt, argv)) == NULL)
			launch_nm("./a.out", hub);
		else
			arg_loop(arg, hub);
		free_arg(arg);
		free_opt(hub->opt);
		free(hub);
	}
	return (0);
}
