/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:24:10 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/05 21:10:44 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_strlen_tab(char **strs)
{
	int	i;

	i = 0;
	while (ft_strlen(strs[i]))
		i++;
	return (i);
}

long long	ft_atoi(const char *str)
{
	long			i;
	int				signe;
	long long int	nbr;

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
	char	**strs;
	int		size;

	strs = check_digit(ac, av);
	size = ft_strlen_tab(strs) + 1;
	//printf("size = %d\n", size);
	if (check_content(size, strs) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (size == 4 || size == 3)
	{
		list_a = ft_list_push_strs(size, strs);
		print_list(list_a);
		if (size == 3)
		{
			if (check_sort(&list_a) == 0)
				sort_s(&list_a, 'a');
		}
		else
			three_value(&list_a);
		free_list(list_a, 0, 0);
	}
	else if (size >= 5)
		sort_all(size + 1, strs);
	return (1);
}
