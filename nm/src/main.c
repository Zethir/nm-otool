/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:30:07 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/07 19:32:44 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

int		check_filetype(t_opt *opt, char *file)
{
	printf("%s\n", file);
	opt = NULL;
	return (0);
}

int		launch_nm(char *bin, t_opt *opt)
{
	int			fd;
	struct stat stat;
	char		*file;
	
	if ((fd = open(bin, O_RDONLY)) < 0)
		return (print_open_error(bin));
	if (fstat(fd, &stat) < 0)
		return (print_fstat_error(bin));
	if (stat.st_size == 0)
		return (print_msg("File is empty\n"));
	if ((stat.st_mode & S_IFMT) == S_IFDIR)
		return (print_msg("Can't read a directory\n"));
	if ((file = mmap(0, stat.st_size,  PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (print_msg("mmap() failed."));
	if (check_filetype(opt, file) < 0)
		return (-1);
	if (munmap(file, stat.st_size) < 0)
		return (print_msg("unmap() failed."));
	return (0);
}

int		get_arg_len(t_arg *arg)
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

void	arg_loop(t_arg *arg, t_opt *opt)
{
	int			i;

	i = get_arg_len(arg);
	while (arg)
	{
		if (i > 1)
			print_binary(arg->bin);
		if (launch_nm(arg->bin, opt) < 0)
			return ;
		arg = arg->next;
	}
}

int		main(int argc, char **argv)
{
	t_opt		*opt;
	t_arg		*arg;

	opt = NULL;
	arg = NULL;
	if (argc == 1)
		launch_nm("./a.out", NULL);
	else
	{
		if ((arg = save_options(&opt, argv)) == NULL)
			launch_nm("./a.out", opt);
		else
			arg_loop(arg, opt);
		free_arg(arg);
		free_opt(opt);
	}
	return (0);
}
