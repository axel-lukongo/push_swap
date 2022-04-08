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
void	init_list(t_list *list, int ac, char **av);
void	print_list(int ac, t_list *beta);
t_list	*ft_lstnew(int content);
#endif // !PUSH_SWAP_H#define PUSH_SWAP_H

