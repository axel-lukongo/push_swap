/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:24:10 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/17 04:11:38 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int main(int ac, char **av)
{
	t_list *list_a;
	t_list *list_b;
	if (ac < 2 || check_digit(ac, av) == 0 || check_content(ac, av) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	list_a = ft_list_push_strs(ac, av);
	list_b = ft_list_push_strs(ac, av);
	init(ac, av, &list_a);
	three_value(&list_a);
	//cost_move(&list_a);
	free_list(list_a);
	free_list(list_b);
	return (1);
}