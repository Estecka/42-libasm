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

#include "main.h"

extern int	main(int argc, char **args)
{
	(void)argc;
	(void)args;
	ft_helloworld();
	test_strlen();
	test_strcpy();
	test_strdup();
	test_strcmp();
	test_write();
	test_read();
}
