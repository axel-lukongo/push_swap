/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:39:27 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/09 14:25:14 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/**
 * @brief in this funciton i check if my list has been sorted
 * 
 * @param list 
 * @return int 
 */
int	check_sort(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*list);
	tmp2 = tmp->next;
	while (tmp->next)
	{
		if (tmp2 == NULL)
		{
			tmp = tmp->next;
			tmp2 = tmp->next;
		}
		if (tmp2)
		{
			if (tmp->value > tmp2->value)
				return (0);
			tmp2 = tmp2->next;
		}
	}
	return (1);
}

/**
 * @brief i sort when i have 4 or 5 number to sort
 * in my conditions i write (size == 6) becausein this size
 * i have the exec. so if a have 5 number + 1 exec, my size is 6 
 * 
 * @param list_a 
 * @param list_b 
 * @param size 
 */
void	sort_five(t_list *list_a, t_list *list_b, int size)
{
	if (size == 6)
	{
		sort_p(&list_b, &list_a, 'b');
		sort_p(&list_b, &list_a, 'b');
	}
	if (size == 5)
		sort_p(&list_b, &list_a, 'b');
	three_value(&list_a);
	send_to_a(&list_a, &list_b);
	free_list(list_a, 0, 0);
}
