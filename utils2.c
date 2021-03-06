/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:18:13 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/07 12:48:38 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
/**
 * @brief in this fonction i check if all my char is a digit and i return 1
 * else 0
 * 
 * @param ac number of number 
 * @param av
 * @return int 
 */
int	ft_digit(int ac, char **av)
{
	int		i;
	char	c;

	while (--ac)
	{
		i = -1;
		while (av[ac][++i])
		{
			c = av[ac][i];
			if ((c < '0' || c > '9') && (c != '-' && c != ' '))
				return (1);
		}
	}
	return (0);
}

/* i should calculat the distance from the top and the bottom of the value in
and stack_b and his sempai and i addition  if the result is smaller than the 
previous i = became this resultat and value became the value of stack_b
i do it while i ain't finish*/
int	search_value(t_list **list_a, t_list **list_b, int i)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		value;

	tmp = *list_a;
	tmp2 = *list_b;
	value = tmp2->value;
	while (tmp2)
	{
		while (tmp)
		{
			if (tmp2->sempai == tmp->value)
			{
				if (i >= tmp2->cost_move + tmp->cost_move)
				{
					i = tmp2->cost_move + tmp->cost_move;
					value = tmp2->value;
				}
			}
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
		tmp = *list_a;
	}
	return (value);
}

/**
 * @brief in this fonction return the number of element in my list
 * 
 * @param begin_list my list
 * @return int number of element
 */
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

/**
 * @brief in this fonction i creat i new element in my list
 * and i initialized the value in my element
 * 
 * @param value 
 * @return t_list* 
 */
t_list	*ft_create_elem(int value)
{
	t_list	*pwd;

	pwd = malloc(sizeof(t_list) * 2);
	if (!pwd)
		return (0);
	pwd -> next = NULL;
	pwd -> value = value;
	return (pwd);
}
