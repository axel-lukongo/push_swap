/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:24:12 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/09 14:37:04 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_sempai_utils(t_list **tmp, t_list **tmp2, int i)
{
	while (*tmp)
	{
		if ((*tmp)->value > (*tmp2)->value)
		{
			if ((*tmp)->value - (*tmp2)->value > 0)
			{
				if ((*tmp)->value - (*tmp2)->value < i)
				{
					(*tmp2)->sempai = (*tmp)->value;
					i = (*tmp)->value - (*tmp2)->value;
				}
			}
		}
		*tmp = (*tmp)->next;
	}
}

/**
 * @brief the sempai is the value bigger than my value but the most close
 * of my value
 * 
 * @param tmp 
 * @param tmp2 
 * @param i 
 */

void	find_sempai(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *list_a;
	tmp2 = *list_b;
	while (tmp2)
	{
		tmp2->sempai = smallest_value(tmp);
		find_sempai_utils(&tmp, &tmp2, 2147483647);
		tmp2 = tmp2->next;
		tmp = *list_a;
	}
}

/**
 * @brief 
	1) search the element in list_a the list_a->value == value,
	when i found it icheck
	the cost_move
	2) if cost_move > size_list/2 i RRA while(*list->value != value)
	3) else i RA while (*list->value != value)
	4) when the value who i want send it on the top on list i push it in list_b
 */

void	pb_condition(t_list **list_a, t_list **list_b, int value)
{
	t_list	*tmp;

	tmp = *list_a;
	while (tmp && tmp->value != value)
		tmp = tmp->next;
	if (tmp)
	{
		if (tmp->cost_move > ft_list_size(tmp) / 2)
			while ((*list_a)->value != value)
				sort_r(list_a, 1, 'a');
		else
			while ((*list_a)->value != value)
				sort_r(list_a, 1, 'a');
		sort_p(list_b, list_a, 'b');
	}
}

/**
 * @brief in this fonction search the LIS value for send it in list_b
 * 1)i check if the value in tmp is in my tab
 * 2)if the value in tmp is in my tab i atribut a cost_move to 
 * all element in my list before to call pb_condition where i send it in b
 * @param list_a 
 * @param list_b 
 * @param tab it contain the value of my LIS
 * @param size_lis it the length of my LIS
 */

void	send_to_b(t_list **list_a, t_list **list_b, int *tab, int size_lis)
{
	int		j;
	t_list	*tmp;

	tmp = (*list_a);
	j = 0;
	while (tmp)
	{
		while (j < size_lis && tab[j] != tmp->value)
			j++;
		if (j >= size_lis)
		{
			cost_move_a(list_a);
			pb_condition(list_a, list_b, tmp->value);
			tmp = *list_a;
		}
		else
			tmp = tmp->next;
		j = 0;
	}
}
