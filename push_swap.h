/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:42:25 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/15 19:50:37 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include"libft/libft.h"
#include"ft_printf/ft_printf.h"

typedef struct s_list
{
	struct s_list *next;
	int value;
	int	median;
	int	biggest_value;
	int	distance;
	int	nb_move;
	int *tab;
} t_list;

int		check_digit(int ac, char **av);
void	init_list(t_list **list, int ac, char **av);
void	print_list(t_list *beta);
void 	free_list(t_list *list);
t_list	*ft_create_elem(int value);
t_list	*ft_list_push_strs(int size,char **strs);
t_list	*ft_list_push_back(t_list **begin_list, t_list *list);
t_list	*ft_list_push_front(t_list **begin_list, t_list *list);
int		check_content(int ac, char **av);
void	sort_s(t_list **list, char c);
//t_list	cort_ss(t_list *list_a, t_list *list_b);
void	sort_p(t_list **list1, t_list **list2, char c);
void	sort_r(t_list **list, char c);
void	sort_rr(t_list **list, char c);
int		ft_list_size(t_list *begin_list);
int		check_sort(t_list **list);
int		init(int ac, char **av, t_list **list);
void	ft_sort_int_tab(int *tab, int size);
int		find_median(int ac, int *tab);
int		find_biggest_value(int ac, int *tab);
int		cost_move(t_list **list);
#endif // !PUSH_SWAP_H#define PUSH_SWAP_H