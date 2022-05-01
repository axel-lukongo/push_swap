/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:42:25 by alukongo          #+#    #+#             */
/*   Updated: 2022/05/02 01:55:55 by alukongo         ###   ########.fr       */
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
	int	sempai;
	int	distance;
	int	cost_move;
	int	*tab;
	int	*tab_lis;
	int	size_lis;
	int	index;
} t_list;

int		check_digit(int ac, char **av);
void	init_list(t_list **list, int ac, char **av);
void	print_list(t_list *beta);
void	free_list(t_list *list, int value, int flag);
t_list	*ft_create_elem(int value);
t_list	*ft_list_push_strs(int size,char **strs);
t_list	*ft_list_push_back(t_list **begin_list, t_list *list);
t_list	*ft_list_push_front(t_list **begin_list, t_list *list);
int		check_content(int ac, char **av);
void	sort_s(t_list **list, char c);
//t_list	cort_ss(t_list *list_a, t_list *list_b);
void	sort_p(t_list **list1, t_list **list2, char c);
void	sort_r(t_list **list, int i, char c);
void	sort_rr(t_list **list, int i, char c);
int		ft_list_size(t_list *begin_list);
int		check_sort(t_list **list);
int		init_tab(int ac, char **av, t_list **list);
//void	ft_sort_int_tab(int *tab, int size);
//int		find_median(int ac, int *tab);
int		lis_pos(int ac, int *tab);
int		cost_move_a(t_list **list);
void	three_value(t_list **list);
void	sort_five(int ac, char **av);
void	sort_all(int ac, char **av);
void	send_to_b(t_list **list_a, t_list **list_b, int	*tab, int size_lis);
int		smallest_value(t_list *list);
void send_to_a(t_list **list_a, t_list **list_b);
#endif // !PUSH_SWAP_H#define PUSH_SWAP_H