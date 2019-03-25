/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_answer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:38:31 by mraymon           #+#    #+#             */
/*   Updated: 2019/03/19 19:38:39 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_square	*ft_create_answer(void)
{
	t_square	*answer;

	answer = (t_square*)malloc(sizeof(t_square));
	return (answer);
}
