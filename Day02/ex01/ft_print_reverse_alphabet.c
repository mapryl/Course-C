/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:54:41 by mapryl            #+#    #+#             */
/*   Updated: 2019/02/28 20:39:05 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_print_reverse_alphabet(void)
{
	char letter;

	letter = 'z';
	while (letter >= 'a')
	{
		ft_putchar(letter);
		letter--;
	}
}
