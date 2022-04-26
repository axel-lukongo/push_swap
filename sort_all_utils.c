/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:24:12 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/26 23:49:30 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//1) search the element in list_a == value, when i found it i check his cost
//2) if cost > size_list/2 i say while(*list->value != value)RRA
//3) else while (*list->value != value) RA
void	pb_condition(t_list **list_a, t_list **list_b, int value)
{
	t_list *tmp;

	tmp = *list_a;
	while (tmp && tmp->value != value)
		tmp = tmp->next;
	if (tmp)
	{
		if (tmp->nb_move > ft_list_size(tmp) / 2)
			while ((*list_a)->value != value)
				sort_rr(list_a, 'a');
		else
			while ((*list_a)->value != value)
				sort_r(list_a, 'a');
		sort_p(list_b, list_a, 'b');
	}
}

void	send_to_b(t_list **list_a, t_list **list_b, int *tab, int size_lis)
{
	int	j;
	t_list *tmp;

	tmp = (*list_a);
	j = 0;
	while (tmp)
	{
			while (j < size_lis && tab[j] != tmp->value)
				j++;
			if (tab[j] == tmp->value)
			{
				cost_move_a(list_a);
				pb_condition(list_a, list_b, tab[j]);
				tmp = *list_a;
			}
			else
				 tmp = tmp->next;
			j = 0;
	}
}