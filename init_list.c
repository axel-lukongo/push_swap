/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:18:29 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/08 18:41:10 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void init_list(t_list **list, int ac, char **av)
{
	int i;
	t_list *list2;
	
	i = 1;
	list2 = malloc(sizeof(t_list));
	list2 = *list;
	while (i < ac)
	{
		list2 = malloc(sizeof(t_list));
		list2->value = ft_atoi(av[i]);
		//printf("list->value = %d\n", list->value);
		list2 = list2->next;
		i++;
	}
	//list = NULL;
	list2 = *list;
	print_list(ac, list2);
}