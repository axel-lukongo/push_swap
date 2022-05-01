/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:21:01 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/02 00:52:53 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_digit(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (i < ac)
	{
		if (av[i][j] != '\0' && isdigit((int)av[i][j]) == 0)
			return (0);
		j++;
		if (av[i][j] == '\0')
		{
			j = 0;
			i++;
		}
	}
	return (1);
}

int	check_content(int ac, char **av)
{
	int	i;
	int	value;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		value = ft_atoi(av[i]);
		if ((value > 2147483647) || (value < -2147483647))
			return (0);
		while (j < ac)
		{
			if (value == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}