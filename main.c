/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:24:10 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/09 15:07:11 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int main(int ac, char **av)
{
	t_list *list;
	if (ac < 2 || check_digit(ac, av) == 0 || check_content(ac, av) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	list = ft_list_push_strs(ac, av);
	print_list(list);
	free_list(list);
	return (1);
}