/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:19:53 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/08 16:00:49 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>
//good
void	print_list(t_list *beta)
{
	int	*c;

	while (beta)
	{
		c = beta->content;
		printf("[%d]--->", *c);
		beta = beta->next;
	}
	printf("NULL");
	printf("\n");
}
