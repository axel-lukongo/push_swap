#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include"libft/libft.h"
#include"ft_printf/ft_printf.h"

typedef struct s_list
{
	struct s_list *next;
	int value;
} t_list;

int		check_digit(int ac, char **av);
void	init_list(t_list **list, int ac, char **av);
void	print_list(t_list *beta);
void 	free_list(t_list *list);
t_list	*ft_create_elem(int value);
t_list	*ft_list_push_strs(int size,char **strs);
int		check_content(int ac, char **av);
t_list	*sort_s(t_list *list);
void	sort_ss(t_list *list_a, t_list *list_b);
void	sort_p(t_list *list1, t_list *list2);
t_list	 *ft_list_push_back(t_list **begin_list, t_list *list);
void	sort_r(t_list *list);
t_list	*ft_list_push_front(t_list **begin_list, t_list *list);
void	sort_rr(t_list *list);
#endif // !PUSH_SWAP_H#define PUSH_SWAP_H