/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 21:17:39 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/10 22:19:54 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELD_H
# define FIELD_H

# include "types.h"

void	set_array(int *array, int size, int value);
t_bool	check_row(t_cell field[][9], int row_number);
t_bool	check_column(t_cell field[][9], int column_number);
t_bool	check_square(t_cell field[][9], int i, int j);
void	copy_field(t_cell source[][9], t_cell destination[][9]);

#endif
