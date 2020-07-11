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

#include "main.h"

static void test(int fd)
{
	ssize_t	exp;
	int		experr;
	ssize_t	got;
	int		goterr;
	char	*buffer;

	printfc(WHITE, 1, "\n> ");
	printfc(CYAN, 1, "%d\n", fd);
	printclear();
	buffer = malloc(21);
	exp = read(fd, buffer, 10);
	experr = errno;
	write(fd, "\n", 1);
	got = ft_read(fd, buffer + 11, 10);
	goterr = errno;
	write(fd, "\n", 1);
	buffer[10] = '\0';
	printf("Expected: %d %zd %s\nGot:      %d %zd %s \n",
		experr, exp, buffer, goterr, got, buffer + 11);
	if (exp == got && experr == goterr)
		printfc(GREEN, 1, "OK\n");
	else
		printfc(RED, 1, "KO\n");
}

extern void	test_read()
{
	printfc(YELLOW, 1, "\n\t# ft_read\n");
	test(0);
	test(1);
	test(2);
	test(-1);
}