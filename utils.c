/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:06:28 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/08 18:05:21 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	print_list(int ac ,t_list *beta)
{
	int	c;

	while (--ac)
	{
		c = beta->value;
		ft_printf("[%d]--->", c);
		beta = beta->next;
	}
	ft_printf("NULL");
	ft_printf("probleme");
	ft_printf("\n");
}

t_list	*ft_lstnew(int content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (0);
	ptr->next = 0;
	ptr->value = content;
	return (ptr);
}
