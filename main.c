/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:24:10 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/04 15:43:53 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	t_list	*list_a;

	if (ac < 2 || check_digit(ac, av) == 0 || check_content(ac, av) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (ac == 4)
	{
		list_a = ft_list_push_strs(ac, av);
		three_value(&list_a);
		free_list(list_a, 0, 0);
	}
	else if (ac == 5 || ac == 6)
		sort_five(ac, av);
	else if (ac > 6)
		sort_all(ac, av);
	return (1);
}
