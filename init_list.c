/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:18:29 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/15 19:27:55 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list *ft_list_push_strs(int size, char **strs)
{
	t_list *element;
	t_list *last_element;
	int i;
	i = 0;
	last_element = 0;
	while (i < size)
	{
		size--;
		element = ft_create_elem(ft_atoi(strs[size]));
		element->next = last_element;
		last_element = element;
	}
	last_element = element;
	element = element->next;
	free(last_element);
	return(element);
}

int	find_median(int ac, int *tab)
{
	int pos_median;
	int median;
	
	if (ac % 2 == 1)
		pos_median = ac / 2;
	if (ac % 2 == 0)
		pos_median = ac / 2 - 1;
	median = tab[pos_median];
	return (median);
}

int	find_biggest_value(int ac, int *tab)
{
	int	i;
	int	value;
	int	next_value;

	value = 0;
	next_value = 1;
	i = 0;
	while (next_value < ac)
	{
		if (tab[i] < tab[next_value])
			i = next_value;
		next_value++;
	}
	value = tab[i];
	return (value);
}

int	init(int ac, char **av, t_list **list)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	(*list)->tab = malloc(sizeof(int) * ac + 1);
	while (av[j])
		(*list)->tab[i++] = ft_atoi(av[j++]);
	(*list)->tab[i] = '\0';
	ft_sort_int_tab((*list)->tab, ac - 1);
	(*list)->median = find_median(ac - 1, (*list)->tab);
	(*list)->biggest_value = find_biggest_value(ac - 1, (*list)->tab);
	return (1);
}