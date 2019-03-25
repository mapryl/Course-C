/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 21:16:35 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/10 22:18:44 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef int	t_bool;
# define TRUE 1
# define FALSE 0

typedef struct	s_cell
{
	int		value;
	t_bool	set;
}				t_cell;

#endif
