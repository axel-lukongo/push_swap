/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:49:46 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/17 17:02:25 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	cost_move(t_list **list)
{
	int	i;
	int	size;
	t_list *tmp;

	tmp = *list;
	i = 0;
	size = ft_list_size(tmp);
	while (i < size)
	{
		if (i >= size / 2)
			tmp->nb_move = (size - i);
		else
			tmp->nb_move = i;
		//printf("value = %d, cost = %d\n", tmp->value, tmp->nb_move);
		i++;
		tmp = tmp->next;
	}
	return (1);
}