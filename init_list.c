/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:18:29 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/14 19:01:55 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list *ft_create_elem(int value)
{
	t_list *pwd;
	if(!(pwd = malloc(sizeof(t_list))))
		return(0);
	pwd -> next = NULL;
	pwd -> value = value;
	return(pwd);
}

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
	printf("value = %d", value);
	return (value);
}