#include"push_swap.h"

int main(int ac, char **av)
{
	p_list list;

	if (ac < 2 || check_digit(ac, av) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	init_list(&list, ac, av);
	return (1);
}