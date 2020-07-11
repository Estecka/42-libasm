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
	char	*exp;
	char	*got;
	char	*gotr;

	exp = malloc(strlen(string) + 1);
	got = malloc(strlen(string) + 1);
	printfc(WHITE, 1, "\n> \"");
	printfc(CYAN, 1, "%s", string);
	printfc(WHITE, 1, "\"\n");
	strcpy(exp, string);
	gotr = ft_strcpy(got, string);
	printf("Expected: %8p %s\nGot:      %8p %s\n", got, exp, gotr, got);
	if (got == gotr && !strcmp(exp, got))
		printfc(GREEN, 1, "OK\n");
	else
		printfc(RED, 1, "KO\n");
	free(exp);
	free(got);
}

extern void	test_strcpy()
{
	printfc(YELLOW, 1, "\n\t# ft_strcpy\n");
	test("Je suis une bulle.");
	test("Beep\0Boop");
	test("");
}