/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:49:46 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/26 23:58:54 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	smallest_value(t_list *list)
{
	int value;
	
	value = list->value;
	while (list)
	{
		if (list->value < value)
			value = list->value;
		list = list->next;
	}
	return (value);
}

void	find_sempai(t_list **list_a, t_list **list_b)
{
	int diff;
	t_list *tmp_a;
	t_list *tmp_b;

	tmp_a = (*list_a);
	tmp_b = (*list_b);
	diff = 2147483647;
	(tmp_b)->sempai = smallest_value((*list_a));
	while (tmp_b)
	{
		while (tmp_a)
		{
			if (tmp_a->value - tmp_b->value > 0)
			{
				if (tmp_a->value - tmp_b->value < diff)
				{
					diff = tmp_a->value - tmp_b->value;
					tmp_b->sempai = tmp_a->value;
				}
			}
			tmp_a = tmp_a->next;
		}
		tmp_a = (*list_a);
		tmp_b = tmp_b->next;
	}
}

/*int	cost_move_b(t_list **list_b)
{
	
}*/

int	cost_move_a(t_list **list_a)
{
	int	i;
	int	size;
	t_list *tmp;

	tmp = *list_a;
	i = 0;
	size = ft_list_size(tmp);
	while (i < size)
	{
		if (i >= size / 2)
			tmp->cost_move = (size - i);
		else
			tmp->cost_move = i;
		i++;
		tmp = tmp->next;
	}
	return (1);
}