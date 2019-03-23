/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:48:28 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/15 21:34:53 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree *node;

	node = malloc(sizeof(node));
	if (node == NULL)
		return (NULL);
	node->item = item;
	node->left = 0;
	node->right = 0;
	return (node);
}
