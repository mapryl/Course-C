/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:41:03 by mraymon           #+#    #+#             */
/*   Updated: 2019/03/19 20:23:20 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "struct.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_square
{
	int i;
	int j;
	int size;
}				t_square;

void			ft_search(int **field, t_square *answer, int h, int n);

void			ft_print_answer(t_map_struct *map, t_square *answer, int h,
		int n);

t_square		*ft_create_answer(void);

#endif
