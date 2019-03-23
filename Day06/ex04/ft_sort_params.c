/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:46:17 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/06 21:40:41 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	unsigned char	s1_n;
	unsigned char	s2_n;

	i = 0;
	s1_n = s1[i];
	s2_n = s2[i];
	while (s1_n != '\0' && s2_n != '\0')
	{
		s1_n = s1[i];
		s2_n = s2[i];
		if (s1_n != s2_n)
			return (s1_n - s2_n);
		i++;
	}
	if ((s1_n == '\0' && s2_n != '\0') ||
			(s2_n == '\0' && s1_n != '\0'))
		return (s1_n - s2_n);
	return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	sort(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < argc - 1)
	{
		i++;
		j = 1;
		while (j < argc - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				argv[argc] = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = argv[argc];
			}
			j++;
		}
	}
}

int		main(int argc, char **argv)
{
	int i;

	sort(argc, argv);
	i = 0;
	while (i < argc - 1)
	{
		i++;
		ft_putstr(argv[i]);
		ft_putchar('\n');
	}
	return (0);
}
