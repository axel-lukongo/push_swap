#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include"libft/libft.h"
#include"ft_printf/ft_printf.h"

typedef struct m_list
{
	struct m_list *next;
	int value;
} p_list;

int		check_digit(int ac, char **av);
void	init_list(p_list *list, int ac, char **av);
void	print_list(int ac, p_list *beta);
#endif // !PUSH_SWAP_H#define PUSH_SWAP_H

