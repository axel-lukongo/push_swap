/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:21:01 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/08 15:57:32 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int check_digit(int ac, char **av)
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
