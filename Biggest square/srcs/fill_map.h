/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:35:56 by mraymon           #+#    #+#             */
/*   Updated: 2019/03/19 19:38:10 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_MAP_H
# define FILL_MAP_H

int					get_line_width(const char *content_str);
void				allocate_2d_map(t_map_struct *result_map, int w, int h);
t_extract_status	fill_2d_map_from_str(t_map_struct *result_map,
		char *content_str);
t_extract_status	fill_map_from_str(t_map_struct *result_map,
		int line_number, char *content_str);

#endif
