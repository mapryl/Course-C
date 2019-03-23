/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:52:39 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/15 21:37:13 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root,
		void *data_ref, int (*cmpf)(void *, void *))
{
	if (root == 0 || data_ref == 0)
		return (0);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	if (root->left)
		return (btree_search_item(root->left, data_ref, cmpf));
	if (root->right)
		return (btree_search_item(root->right, data_ref, cmpf));
	return (0);
}
