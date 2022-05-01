/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:25:27 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/02 01:56:18 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	*init_to_one(int *tab, int size)
{
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return(NULL);
	while (i < size)
	{
		tab[i] = 1;
		i++;
	}
	return (tab);
}

int	*lis_value(t_list *list, int *tab, int lis_pos)
{
	int	j;
	int *tab_lis;
	int i;
	
	tab_lis = malloc(sizeof(int) * lis_pos + 1);
	if (!tab_lis)
		return (0);
	tab[lis_pos] = 1;
	j = 0;
	i = 0;
	while (j < lis_pos)
	{
		if (list->tab[j] < list->tab[lis_pos] && tab[j] + 1 > tab[lis_pos])
			{
				tab_lis[i] = list->tab[j];
				tab[lis_pos] = tab[j] + 1;
				i++;
			}
		j++;
	}
	tab_lis[i] = list->tab[lis_pos];
	free(tab);
	return (tab_lis);
}

int	*find_lis(t_list *list, t_list **list_a)
{
	int	i;
	int	j;
	int	*tab;

	i = 1;
	tab = NULL;
	tab = init_to_one(tab, ft_list_size(list));
	if (!tab)
		return (0);
	while (i < ft_list_size(list))
	{
		j = 0;
		while (j < i)
		{
			if (list->tab[j] < list->tab[i] && tab[j] + 1 > tab[i])
				tab[i] = tab[j] + 1;
			j++;
		}
		i++;
	}
	(*list_a)->size_lis = tab[lis_pos(i, tab)];
	return (lis_value(list ,tab, lis_pos(i, tab)));
}

void	sort_all(int ac, char **av)
{
	int		value;
	t_list *list_a;
	t_list *list_b;
	list_a = ft_list_push_strs(ac, av);
	list_b = NULL;
	if (init_tab(ac, av, &list_a))
	{
		list_a->tab_lis = find_lis(list_a, &list_a);
		if (list_a->tab_lis)
		{
			value = list_a->value;
			send_to_b(&list_a, &list_b, list_a->tab_lis, list_a->size_lis);
			send_to_a(&list_a, &list_b);
		}
	}
	print_list(list_a);
	free_list(list_a, value, 1);
	return ;
}