#include "push_swap.h"

bool	isAllDigit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}

void	setupStacks(t_stack *a, t_stack *b, char **av, bool debug)
{
	int	i;
	int	j;

	i = 1;
	if (debug)
	{
		a->size--;
		i++;
	}
	b->size = a->size;
	a->stack = malloc(sizeof(int) * a->size);
	b->stack = malloc(sizeof(int) * b->size);
	if (!a->stack || !b->stack)
		exit(1);
	a->currentSize = 0;
	b->currentSize = 0;
	j = 0;
	while (av[i])
	{
		a->stack[j] = ft_atoi(av[i]);
		a->currentSize++;
		j++;
		i++;
	}
}

void	cleanupStacks(int **a, int **b)
{
	free(*a);
	free(*b);
}

void	printStacks(t_stack a, t_stack b)
{
	int	i;

	write(1, "stack a:\n", 9);
	i = a.size - 1;
	while (i >= 0)
	{
		if (i >= a.currentSize)
			write(1, "---", 3);
		else
			ft_putnbr_fd(a.stack[i], 1);
		write(1, "\n", 1);
		i--;
	}
	write(1, "stack b:\n", 9);
	i = a.size - 1;
	while (i >= 0)
	{
		if (i >= b.currentSize)
			write(1, "---", 3);
		else
			ft_putnbr_fd(b.stack[i], 1);
		write(1, "\n", 1);
		i--;
	}
}

bool	isSorted(t_stack s)
{
	int	i;

	if (s.size != s.currentSize)
		return (false);
	i = 0;
	while (i < s.size - 1)
	{
		if (s.stack[i] > s.stack[i + 1])
			return (false);
		i++;
	}
	return (true);
}
