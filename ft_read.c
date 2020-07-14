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

static void test_path(char *path)
{
	int		fd;
	ssize_t	exp;
	int		experr;
	ssize_t	got;
	int		goterr;
	char	*buffer;

	printfc(WHITE, 1, "\n> ");
	printfc(CYAN, 1, "%s\n", path);
	buffer = malloc(40);
	memset(buffer, 0, 20);

	fd = open(path, O_RDONLY);
	errno = 0;
	exp = read(fd, buffer, 19);
	close(fd);
	experr = errno;

	fd = open(path, O_RDONLY);
	errno = 0;
	got = ft_read(fd, buffer + 20, 19);
	goterr = errno;
	close(fd);

	buffer[19] = '\0';
	buffer[39] = '\0';
	printf("Expected: %d %zd %s\nGot:      %d %zd %s \n",
		experr, exp, buffer, goterr, got, buffer + 20);
	if (exp == got && experr == goterr && !strncmp(buffer, buffer + 20, 20))
		printfc(GREEN, 1, "OK\n");
	else
		printfc(RED, 1, "KO\n");
	close(fd);
}

static void test_fd(int fd)
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

extern void	test_read()
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