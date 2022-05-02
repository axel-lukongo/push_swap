/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:18:13 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/02 14:18:25 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}

int	check_sort(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*list);
	tmp2 = tmp;
	while (tmp->next)
	{
		if (tmp2->next == NULL)
		{
			tmp = tmp->next;
			tmp2 = tmp;
		}
		tmp2 = tmp2->next;
		if (tmp->value > tmp2->value)
			return (0);
	}
	return (1);
}

t_list	*ft_create_elem(int value)
{
	t_list	*pwd;

	pwd = malloc(sizeof(t_list));
	if (!pwd)
		return (0);
	pwd -> next = NULL;
	pwd -> value = value;
	return (pwd);
}
