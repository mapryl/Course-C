/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 21:11:23 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/15 21:39:36 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int left_c;
	int right_c;

	left_c = 0;
	right_c = 0;
	if (root == 0)
		return (0);
	if (root->left)
		left_c = btree_level_count(root->left);
	if (root->right)
		right_c = btree_level_count(root->right);
	if (left_c > right_c)
		return (left_c + 1);
	else
		return (right_c + 1);
}
