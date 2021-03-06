/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:37:58 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/05 12:46:58 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_s(t_list **list, char c)
{
	t_list	*list2;

	list2 = (*list)->next;
	(*list)->next = list2->next;
	list2->next = *list;
	*list = list2;
	ft_printf("s%c\n", c);
}

void	sort_p(t_list **list1, t_list **list2, char c)
{
	t_list	*tmp;

	tmp = (*list2)->next;
	(*list2)->next = *list1;
	*list1 = *list2;
	*list2 = tmp;
	ft_printf("p%c\n", c);
}

void	sort_r(t_list **list, int i, char c)
{
	t_list	*tmp;

	tmp = (*list)->next;
	(*list)->next = NULL;
	*list = ft_list_push_back(&tmp, *list);
	if (i > 0)
		ft_printf("r%c\n", c);
}

void	sort_rr(t_list **list, int i, char c)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *list;
	tmp2 = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	*list = ft_list_push_front(list, tmp);
	if (i > 0)
		ft_printf("rr%c\n", c);
}
