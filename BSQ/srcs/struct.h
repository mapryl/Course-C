/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 18:58:50 by mraymon           #+#    #+#             */
/*   Updated: 2019/03/19 19:03:32 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_map_struct
{
	int			w;
	int			h;
	int			**field;
	int			need_free;
	char		empty_char;
	char		obstcl_char;
	char		full_char;
}				t_map_struct;

typedef enum	e_extract_status
{
	extract_ok,
	extract_error
}				t_extract_status;

#endif
