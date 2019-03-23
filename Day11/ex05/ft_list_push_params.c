/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:23:09 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/13 20:39:02 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*new_node;
	int		i;
	t_list	*head;

	if (ac <= 0)
		return (0);
	i = 0;
	head = 0;
	while (i < ac)
	{
		new_node = ft_create_elem(av[i]);
		new_node->next = head;
		head = new_node;
		i++;
	}
	return (new_node);
}
