/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:18:29 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/08 18:07:08 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void init_list(t_list *list, int ac, char **av)
{
	int i;
	t_list *list2;
	
	i = 1;
	list2 = list;
	while (i < ac - 2)
	{
		list = ft_lstnew(ft_atoi(av[i]));
		list = list->next;
		i++;
	}
	//list->next = NULL;
	print_list(ac, list2);
}