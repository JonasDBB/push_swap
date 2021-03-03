#include "push_swap.h"

void	checker(bool debug, t_stack *a, t_stack *b)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, "STOP"))
			break ;
		findOp(a, b, line);
		if (debug)
			printStacks((*a), (*b));
	}
	printStacks((*a), (*b));
	if (isSorted((*a)))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int		i;
	bool	debug;
	t_stack	a;
	t_stack	b;

	i = 1;
	debug = false;
	if (!ft_strcmp(av[1], "-v"))
	{
		debug = true;
		i++;
	}
	while (av[i])
	{
		if (!isAllDigit(av[i]))
		{
			write(1, "KO\n", 3);
			return (1);
		}
		i++;
	}
	a.size = ac - 1;
	setupStacks(&a, &b, av, debug);
	checker(debug, &a, &b);
	cleanupStacks(&a.stack, &b.stack);
}
