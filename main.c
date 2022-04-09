#include"push_swap.h"

int main(int ac, char **av)
{
	t_list *list;
	if (ac < 2 || check_digit(ac, av) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	list = ft_list_push_strs(ac, av);
	print_list(ac, list);
	free_list(list);
	return (1);
}