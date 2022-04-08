/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:06:28 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/08 16:31:15 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	print_list(int ac ,p_list *beta)
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
