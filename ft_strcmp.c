/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 09:57:00 by abaur             #+#    #+#             */
/*   Updated: 2020/07/11 09:57:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	test(const char *src, const char *dst)
{
	int	exp;
	int	got;

	printfc(WHITE, 1, "\n> \"");
	printfc(CYAN, 1, "%s", src);
	printfc(WHITE, 1, "\", \"");
	printfc(CYAN, 1, "%s", dst);
	printfc(WHITE, 1, "\"\n");
	exp = strcmp(src, dst);
	got = ft_strcmp(src, dst);
	printf("Expected: %+d \nGot:      %+d \n", exp, got);
	if (exp == got)
		printfc(GREEN, 1, "OK\n");
	else
		printfc(RED, 1, "KO\n");
}

extern void	test_strcmp(void)
{
	printfc(YELLOW, 1, "\n\t# ft_strcmp\n");
	test("Je suis une bulle.", "Je suis une bulle");
	test("12345", "123450");
	test("12345", "12346");
	test("", "");
}
