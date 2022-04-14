/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:18:13 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/14 19:02:25 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int ft_list_size(t_list *begin_list)
{
	int count;
	count = 0;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		count++;
	}
	return(count);
}

int	check_sort(t_list **list)
{
	t_list *tmp;
	t_list *tmp2;

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

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	n;
	int	swap;

	i = 0;
	n = i + 1;
	while (i < size - 1)
	{
		if (tab[n] < tab[i])
		{
			swap = tab[i];
			tab[i] = tab[n];
			tab[n] = swap;
			i = 0;
			n = i + 1;
		}
		else
		{
			i++;
			n = i + 1;
		}
	}
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
	//printf("(*list)->median = %d", (*list)->median);
	return (1);
}
