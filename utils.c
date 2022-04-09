/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:06:28 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/09 02:39:28 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	print_list(int ac ,t_list *beta)
{
	(void) ac;
	while (beta)
	{
		printf("[%d]--->", beta->value);
		beta = beta->next;
	}
	printf("NULL");
	printf("\n");
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

t_list *ft_create_elem(int value)
{
	t_list *pwd;
	if(!(pwd = malloc(sizeof(t_list))))
		return(0);
	pwd -> next = NULL;
	pwd -> value = value;
	//printf("%s\n",pwd ->value);
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
	return(element);
}