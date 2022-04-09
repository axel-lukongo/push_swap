#include"push_swap.h"

int main(int ac, char **av)
{
	t_list *list;

	//list.next = 0;
	/*if (ac < 2 || check_digit(ac, av) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}*/
	//init_list(&list, ac, av);
	list = ft_list_push_strs(ac, av);
	print_list(ac, list);
	return (1);
}