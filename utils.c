/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:06:28 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/09 15:06:44 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	print_list(t_list *beta)
{
	while (beta)
	{
		printf("[%d]--->", beta->value);
		beta = beta->next;
	}
	printf("NULL");
	printf("\n");
}

void free_list(t_list *list)
{
	t_list *list2;

	list2 = list->next;
	while (list2)
	{
		free(list);
		list = list2;
		list2 = list2->next;
	}
	free(list);
}
