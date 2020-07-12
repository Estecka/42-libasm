/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
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

	printfc(WHITE, 1, "\n> \"");
	printfc(CYAN, 1, "%s", string);
	printfc(WHITE, 1, "\"\n");
	exp = strdup(string);
	got = ft_strdup(string);
	printf("Expected: %s\nGot:      %s\n", exp, got);
	if (!strcmp(exp, got))
		printfc(GREEN, 1, "OK\n");
	else
		printfc(RED, 1, "KO\n");
	if (exp)
		free(exp);
	if (got)
		free(got);
}

extern void	test_strdup()
{
	printfc(YELLOW, 1, "\n\t# ft_strdup\n");
	test("Je suis une bulle.");
	test("Beep\0Boop");
	test("");
}