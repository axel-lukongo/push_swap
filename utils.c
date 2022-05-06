/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:06:28 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/06 15:22:11 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	print_list(t_list *beta)
{
	while (beta)
	{
		printf("[%d]--->", beta->value);
		beta = beta->next;
	}
	printf("NULL");
	printf("\n");
}

int	find_smallest(t_list *list)
{
	t_list	*tmp;
	int		value;

	tmp = list;
	value = tmp->value;
	while (tmp)
	{
		if (value > tmp->value)
			value = tmp->value;
		tmp = tmp->next;
	}
	return (value);
}

/*
when value != 0 it mean i have to free the tab
flag = 1 it mean i want else i don't want free
*/
void	free_list(t_list *list, int value, int flag)
{
	t_list	*list2;

	list2 = list->next;
	while (list2)
	{
		if (list->value == value && flag == 1)
			free(list->tab_lis);
		if (list->value == value && flag == 1)
			free(list->tab);
		free(list);
		list = list2;
		list2 = list2->next;
	}
	free(list);
}

t_list	*ft_list_push_back(t_list **begin_list, t_list *list)
{
	t_list	*li;

	li = *begin_list;
	if (!li)
	{
		*begin_list = list;
		return (*begin_list);
	}
	else
	{
		while (li->next != NULL)
		{
			li = li->next;
		}
		li->next = list;
	}
	return (*begin_list);
}

t_list	*ft_list_push_front(t_list **begin_list, t_list *list)
{
	t_list	*li;

	li = NULL;
	if (!(begin_list))
		*begin_list = list;
	else
	{
		li = list;
		li->next = *begin_list;
		*begin_list = li;
	}
	return (*begin_list);
}
