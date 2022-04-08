#include"push_swap.h"

int main(int ac, char **av)
{
	if (ac < 2 || check_digit(ac, av) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
}