/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:37:00 by abaur             #+#    #+#             */
/*   Updated: 2020/07/06 14:37:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

# include "libasm.h"
# include "logutil/logutil.h"

void	test_strlen();
void	test_strcpy();
void	test_strcmp();
void	test_write();
void	test_read();
void	test_strdup();

#endif
