/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 09:57:00 by abaur             #+#    #+#             */
/*   Updated: 2020/07/11 09:57:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void test(const char *string)
{
	int exp, got;

	printfc(WHITE, 1, "\n> \"");
	printfc(CYAN, 1, "%s", string);
	printfc(WHITE, 1, "\"\n");
	exp = strlen(string);
	got = ft_strlen(string);
	printf("Expected: %d \nGot:      %d \n", exp, got);
	if (exp == got)
		printfc(GREEN, 1, "OK\n");
	else
		printfc(RED, 1, "KO\n");
}

extern void	test_strlen()
{
	printfc(YELLOW, 1, "\n\t# ft_strlen\n");
	test("Je suis une bulle.");
	test("Beep\0Boop");
	test("");
}