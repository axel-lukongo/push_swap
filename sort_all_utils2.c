/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:59:32 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/30 01:33:20 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_sempai(t_list **list_a, t_list **list_b)
{
	int	i;
	t_list *tmp;
	t_list *tmp2;

	tmp = *list_a;
	tmp2 = *list_b;
	i = 2147483647;
	tmp2->sempai = smallest_value(tmp);
	while (tmp2)
	{
		while (tmp)
		{
			if (tmp->value > tmp2->value)
				if(tmp->value - tmp2->value > 0)
					if (tmp->value - tmp2->value < i)
					{
						tmp2->sempai = tmp->value;
						i = tmp->value - tmp2->value;
					}
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
		tmp = *list_a;
		i = 2147483647;
	}
}

int search_value(t_list **list_a, t_list **list_b)
{
	t_list *tmp;
	t_list *tmp2;
	int	i;
	int value;
	
	i = 2147483647;
	tmp = *list_a;
	tmp2 = *list_b;
	value = tmp2->value;
	while (tmp2)
	{
		while (tmp)
		{
			if (tmp2->sempai == tmp->value)
				if (i < (tmp2->cost_move + tmp->cost_move))
				{
					i = tmp2->cost_move + tmp->cost_move;
					value = tmp2->value;
				} 
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	return (value);
}

void shift_elem2(t_list **list_a, t_list **list_b, int value_a, int value_b)
{
	if ((*list_b)->index > ft_list_size(*list_b) / 2)
		while ((*list_b)->value != value_b)
			sort_rr(list_b, 1, 'b');
	else
		while ((*list_b)->value != value_b)
			sort_r(list_b, 1, 'b');
	if ((*list_a)->index > ft_list_size(*list_a) / 2)
		while ((*list_a)->value != value_a)
			sort_rr(list_a,1, 'a');
	else
		while ((*list_a)->value != value_a)
			sort_rr(list_a, 1, 'a');
}

void shift_elem(t_list **list_a, t_list **list_b, int value_a, int value_b)
{
	/*if ((*list_a)->index > ft_list_size(*list_a) / 2
	&& (*list_b)->index > ft_list_size(*list_b) / 2)
		while ((*list_b)->value != value_b && (*list_a)->value != value_a)
		{
				sort_rr(list_b, 0, 'r');			
				sort_rr(list_a,1, 'r');
		}
	else
		while ((*list_b)->value != value_b && (*list_a)->value != value_a)
		{
				sort_r(list_a, 0, 'r');
				sort_r(list_b, 1, 'r');
		}*/
	shift_elem2(list_a, list_b, value_a, value_b);
}

void move_elem(t_list **list_a, t_list **list_b, int value)
{
	t_list *tmp;
	t_list *tmp2;
	int	i;

	i = 0;
	tmp = *list_a;
	tmp2 = *list_b;
	while (tmp2->value != value)
	{
		i++;
		tmp2 = tmp->next;
	}
	(*list_b)->index = i;
	i = 0;
	while (tmp->value != tmp2->sempai)
	{
		i++;
		tmp = tmp->next;
	}
	(*list_a)->index = i;
	shift_elem(list_a, list_b, tmp->value, value);
}

void send_to_a(t_list **list_a, t_list **list_b)
{
	int	value;
	int	smallest;
	int	i;
	t_list	*tmp;
	
	i = 0;
	while (*list_b)
	{
		find_sempai(list_a, list_b);
		cost_move_a(list_a);
		cost_move_a(list_b);
		value = search_value(list_a, list_b);
		move_elem(list_a, list_b, value);
		sort_p(list_a, list_b, 'a');
	}
	smallest = smallest_value(*list_a);
	tmp = (*list_a);
	while (tmp->value != smallest)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > ft_list_size(*list_a) / 2)
		while ((*list_a)->value != smallest)
			sort_rr(list_a, 1, 'a');
	else
		while ((*list_a)->value != smallest)
			sort_r(list_a, 1, 'a');
	//print_list(*list_a);
}
