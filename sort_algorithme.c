/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithme.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:38:43 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/17 04:45:21 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void first_case(t_list *list)
{
	int	value1;
	int	value2;

	value1 = list->value - list->next->next->value;
	value2 = list->value - list->next->value;
	if (value1 < 0)
		sort_s(&list, 'a');
	else if (value1 > value2)
		{
			sort_s(&list, 'a');
			sort_rr(&list, 'a');
		}
	else if (value1 < value2)
		sort_r(&list, 'a');
}

void other_case(t_list *list)
{
	int	value;

	value = list->value - list->next->next->value;
	if (value < 0)
	{
		sort_s(&list, 'a');
		sort_r(&list, 'a');
	}
	else
		sort_rr(&list, 'a');
}

void three_value(t_list **list)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = (*list);
	if (check_sort(list) == 0)
	{
		if (tmp->value > tmp->next->value)
			first_case(tmp);
		else
			other_case(tmp);
	}
	print_list(*list);
}