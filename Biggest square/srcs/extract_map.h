/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:23:38 by mraymon           #+#    #+#             */
/*   Updated: 2019/03/20 14:05:45 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRACT_MAP_H
# define EXTRACT_MAP_H

int					ft_atoi(char *str, char *end);
int					get_line_numbers(char **str);
t_extract_status	get_special_chars(t_map_struct *result_map,
		char **content_str);
t_extract_status	try_extract_map(t_map_struct *result_map,
		char *content_str);

#endif
