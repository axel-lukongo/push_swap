/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:18:29 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/08 16:49:35 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void init_list(p_list *list, int ac, char **av)
{
	int i;
	p_list *list2;
	
	i = 1;
	list2 = list;
	while (i < ac)
	{
		list->value = ft_atoi(av[i]);
		list = list->next;
		i++;
	}
	list = NULL;
	print_list(ac, list2);
}