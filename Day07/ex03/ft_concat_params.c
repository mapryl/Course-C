/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:38:41 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/07 17:17:56 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		sum_len;
	char	*array;
	int		j;
	int		k;

	i = 0;
	sum_len = 0;
	while (i < argc - 1)
	{
		i++;
		sum_len += ft_strlen(argv[i]) + 1;
	}
	array = (char*)malloc(sizeof(char)*sum_len);
	i = 0;
	k = 0;
	while (i < argc - 1)
	{
		i++;
		j = 0;
		while (argv[i][j] != '\0')
			array[k++] = argv[i][j++];
		if (i == argc - 1)
			array[k++] = '\0';
		else
			array[k++] = '\n';
	}
	return (array);
}
