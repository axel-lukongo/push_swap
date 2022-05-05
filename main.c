/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:24:10 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/05 12:42:25 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_atoi(const char *str)
{
	long	i;
	int		signe;
	int		nbr;

	nbr = 0;
	signe = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			signe = signe * 1;
		if (str[i] == '-')
			signe = signe * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	nbr = nbr * signe;
	return (nbr);
}

int	main(int ac, char **av)
{
	t_list	*list_a;

	if (ac < 2 || check_digit(ac, av) == 0 || check_content(ac, av) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (ac == 4 || ac == 3)
	{
		list_a = ft_list_push_strs(ac, av);
		if (ac == 3)
		{
			if (check_sort(&list_a) == 0)
				sort_s(&list_a, 'a');
		}
		else
			three_value(&list_a);
		free_list(list_a, 0, 0);
	}
	else if (ac >= 5)
		sort_all(ac, av);
	return (1);
}
