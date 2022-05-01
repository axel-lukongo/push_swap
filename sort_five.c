/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:24:11 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/02 01:57:27 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_list *list)
{
	t_list *tmp;
	int value;

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

void send_small_value(int smallest, t_list **list_a, t_list **list_b)
{
	int	i;
	int	size;
	t_list *tmp;
	(void) list_b;
	tmp = *list_a;
	i = 0;
	size = ft_list_size(*list_a);
	while (tmp->value != smallest)
	{
		i++;
		tmp = tmp->next;
	}
	if (i > size / 2)
		while (i++ < size)
			sort_r(list_a, 1, 'a');
	else
		while (i--)
			sort_r(list_a, 1, 'a');
	sort_p(list_b, list_a, 'b');
}

void sort_five(int ac, char **av)
{
	t_list *list_a;
	t_list *list_b;
	int	size;
	int small_value;

	list_a = ft_list_push_strs(ac, av);
	list_b = NULL;
	size = ft_list_size(list_a);
	if (size == 5 || size == 4)
	{
		while (ft_list_size(list_a) > 3)
		{
			small_value = find_smallest(list_a);
			send_small_value(small_value, &list_a, &list_b);
		}
		three_value(&list_a);
		while (--size >= 3)
			sort_p(&list_a, &list_b, 'a');
		print_list(list_a);
	}
	free_list(list_a, 0, 0);
}