/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:18:29 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/02 14:01:12 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*element;
	t_list	*last_element;
	int		i;

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
	return (element);
}

int	init_tab(int ac, char **av, t_list **list)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	(*list)->tab = malloc(sizeof(int) * ac + 1);
	if (!(*list)->tab)
		return (0);
	while (av[j])
		(*list)->tab[i++] = ft_atoi(av[j++]);
	(*list)->tab[i] = '\0';
	return (1);
}

int	lis_pos(int ac, int *tab)
{
	int	i;
	int	next_value;

	next_value = 1;
	i = 0;
	while (next_value < ac)
	{
		if (tab[i] < tab[next_value])
			i = next_value;
		next_value++;
	}
	return (i);
}
