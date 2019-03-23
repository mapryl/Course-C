/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:37:13 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/14 18:23:06 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	error_print(int err_num)
{
	if (err_num == 21)
		write(2, ": Is a directory\n", 17);
	if (err_num == 13)
		write(2, ": Permission denied\n", 20);
	if (err_num == 2)
		write(2, ": No such file or directory\n", 28);
}

void	print_file(int argc, char **argv)
{
	int		i;
	int		fd;
	char	buf[28676];
	int		ret;

	i = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDWR);
		if (fd < 0)
		{
			write(2, "cat: ", 5);
			write(2, argv[i], ft_strlen(argv[i]));
			error_print(errno);
			continue ;
		}
		while ((ret = read(fd, &buf, 28676)))
		{
			buf[ret] = '\0';
			ft_putstr(buf);
		}
		close(fd);
	}
}

int		main(int argc, char **argv)
{
	char	c;
	int		n;

	if (argc == 1)
	{
		while (read(0, &c, 1) > 0)
			write(1, &c, 1);
	}
	else
		print_file(argc, argv);
	return (0);
}
