/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:30:07 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/12 17:44:49 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

int				check_filetype(char *file, char *bin)
{
	uint32_t	magic;

	magic = *(int *)file;
	if (magic == MH_MAGIC)
		handle_32(file);
	else if (magic == MH_MAGIC_64)
		handle_64(file);
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
		handle_fat(file, bin);
	else if (!ft_strncmp(file, ARMAG, SARMAG))
		handle_ar(file, bin);
	else
	{
		return (
			print_msg("The file wasn't recognized as a valid object file\n"));
	}
	return (0);
}

static int		launch_otool(char *bin)
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
	if ((file = mmap(0, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
			== MAP_FAILED)
		return (print_msg("mmap() failed."));
	if (check_filetype(file, bin) < 0)
		return (-1);
	if (munmap(file, stat.st_size) < 0)
		return (print_msg("unmap() failed."));
	return (0);
}

int				main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		launch_otool("./a.out");
	else
	{
		while (argv[i])
		{
			print_binary(argv[i]);
			if (launch_otool(argv[i]) < 0)
				return (-1);
			i++;
		}
	}
	return (0);
}
