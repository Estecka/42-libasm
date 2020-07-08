/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:37:00 by abaur             #+#    #+#             */
/*   Updated: 2020/07/06 14:37:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "libasm.h"

extern int	main(int argc, char **args)
{
	(void)argc;
	(void)args;

	ft_helloworld();

	char* strings[] = {
		"Je suis un test.",
		"Je suis une bulle",
		"",
	};

	for (int i=0; i<3; i++)
		printf("%s \n%lu / %lu \n\n", 
			strings[i], 
			ft_strlen(strings[i]), 
			strlen(strings[i])
		);
}
