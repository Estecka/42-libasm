/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 09:57:00 by abaur             #+#    #+#             */
/*   Updated: 2020/07/11 09:57:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "main.h"

static void	test_path(char *path)
{
	int		fd;
	ssize_t	rval;
	int		err;
	char	buff[20];

	printfc(WHITE, 1, "\n> ");
	printfc(CYAN, 1, "%s\n", path);
	errno = 0;
	fd = open(path, O_RDONLY);
	printfc(MAGENTA, 1, "fd %d opened with errno %d\n", fd, errno);
	errno = 0;
	rval = ft_read(fd, buff, 20);
	err = errno;
	close(fd);
	printf("Got:      %d %zd %.20s \n",
		err, rval, buff);
}

static void	test_fd(int fd)
{
	ssize_t	got;
	int		goterr;
	char	*buffer;

	printfc(WHITE, 1, "\n> ");
	printfc(CYAN, 1, "%d\n", fd);
	printclear();
	buffer = malloc(20);
	memset(buffer, 0, 20);
	got = ft_read(fd, buffer, 20);
	goterr = errno;
	buffer[19] = '\0';
	printf("Got:      %d %zd %19s \n",
		goterr, got, buffer);
}

extern void	test_read(void)
{
	printfc(YELLOW, 1, "\n\t# ft_read\n");
	test_path("./ft_read.c");
	test_path("./ft_read.s");
	test_path("./ft_strdup.s");
	test_path("./makefile");
	test_path("./.gitignore");
	test_path("./gnouh");
	test_fd(-1);
	test_fd(0);
	test_fd(1);
	test_fd(2);
}
