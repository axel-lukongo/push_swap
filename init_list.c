/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:18:29 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/09 15:04:46 by alukongo         ###   ########.fr       */
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