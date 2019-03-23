/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:41:15 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/12 14:03:12 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		calculate(int a, int b, int operation);
int		ft_atoi(char *str);
int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_mul(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);
int		ft_power(int a, int b);

#endif
