/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:21:30 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/13 20:39:49 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *temp;

	if (begin_list == 0 || *begin_list == 0)
	{
		return ;
	}
	while (*begin_list != 0)
	{
		temp = *begin_list;
		*begin_list = temp->next;
		free(temp);
	}
	*begin_list = 0;
}
