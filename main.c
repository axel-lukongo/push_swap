#include"push_swap.h"

int main(int ac, char **av)
{
	int test;
	test = check_digit(ac, av);
	ft_printf("test = %d\n",test);
	if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	
}