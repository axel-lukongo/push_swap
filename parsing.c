/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:21:01 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/06 01:59:33 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

 int	check_n_of_words(char *s, char sep)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

char	**check_digit(int ac, char **av)
{
	char	**sa;
	char	*s;
	int		i;

	if (ft_digit(ac, av))
		return (NULL);
	s = malloc(sizeof(char));
	if (!s)
		return (NULL);
	s[0] = '\0';
	i = 0;
	while (++i < ac)
	{
		if (!av[i])
			break ;
		s = ft_strjoin(s, av[i]);
		if (!s)
			return (NULL);
	}
	sa = ft_strsplit(s, ' ');
	free(s);
	if (!sa)
		return (NULL);
	return (sa);
}

int	check_content(int ac, char **av)
{
	int				i;
	long long int	value;
	int				j;

	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		value = ft_atoi(av[i]);
		if ((value > 2147483647) || (value < -2147483647))
			return (0);
		while (j < ac - 1)
		{
			if (value == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
