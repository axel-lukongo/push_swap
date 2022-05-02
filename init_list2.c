/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:49:46 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/02 14:01:37 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	smallest_value(t_list *list)
{
	int	value;

	value = list->value;
	while (list)
	{
		if (list->value < value)
			value = list->value;
		list = list->next;
	}
	return (value);
}

int	cost_move_a(t_list **list_a)
{
	int		i;
	int		size;
	t_list	*tmp;

	tmp = *list_a;
	i = 0;
	size = ft_list_size(tmp);
	while (i < size)
	{
		if (i >= size / 2)
			tmp->cost_move = (size - i);
		else
			tmp->cost_move = i;
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
	return (1);
}
