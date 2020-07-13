/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 09:57:00 by abaur             #+#    #+#             */
/*   Updated: 2020/07/11 09:57:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void test(int fd, const char* buffer, size_t count)
{
	ssize_t	exp;
	int	experr;
	ssize_t	got;
	int	goterr;

	printfc(WHITE, 1, "\n> ");
	printfc(CYAN, 1, "%d", fd);
	printfc(WHITE, 1, " \"");
	printfc(CYAN, 1, "%s", buffer);
	printfc(WHITE, 1, "\" ");
	printfc(CYAN, 1, "%lu\n", count);
	printclear();
	exp = write(fd, buffer, count);
	experr = errno;
	write(fd, "\n", 1);
	errno = 0;
	got = ft_write(fd, buffer, count);
	goterr = errno;
	write(fd, "\n", 1);
	printf("Expected: %d %zd \nGot:      %d %zd \n", experr, exp, goterr, got);
	if (exp == got && experr == goterr)
		printfc(GREEN, 1, "OK\n");
	else
		printfc(RED, 1, "KO\n");
}

extern void	test_write()
{
	printfc(YELLOW, 1, "\n\t# ft_write\n");
	test(0, "Je suis une Bulle.", 17);
	test(1, "0123456789\0000123456798", 21);
	test(2, "StdErr", 6);
	test(-1, "Bye", 3);
}