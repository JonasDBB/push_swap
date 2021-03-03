#include "push_swap.h"

bool	findSwap(t_stack *a, t_stack *b, const char *op)
{
	if (!ft_strcmp(op, "sa"))
	{
		swapTop(&(*a));
		return (true);
	}
	if (!ft_strcmp(op, "sb"))
	{
		swapTop(&(*b));
		return (true);
	}
	if (!ft_strcmp(op, "ss"))
	{
		swapTop(&(*a));
		swapTop(&(*b));
		return (true);
	}
	return (false);
}

bool	findPush(t_stack *a, t_stack *b, const char *op)
{
	if (!ft_strcmp(op, "pa"))
	{
		push(&(*a), &(*b));
		return (true);
	}
	else if (!ft_strcmp(op, "pb"))
	{
		push(&(*b), &(*a));
		return (true);
	}
	return (false);
}

bool	findRotate(t_stack *a, t_stack *b, const char *op)
{
	if (!ft_strcmp(op, "ra"))
	{
		rotate(&(*a));
		return (true);
	}
	if (!ft_strcmp(op, "rb"))
	{
		rotate(&(*b));
		return (true);
	}
	if (!ft_strcmp(op, "rs"))
	{
		rotate(&(*a));
		rotate(&(*b));
		return (true);
	}
	return (false);
}

bool	findRevRotate(t_stack *a, t_stack *b, const char *op)
{
	if (!ft_strcmp(op, "rra"))
	{
		rrotate(&(*a));
		return (true);
	}
	if (!ft_strcmp(op, "rrb"))
	{
		rrotate(&(*b));
		return (true);
	}
	if (!ft_strcmp(op, "rrs"))
	{
		rrotate(&(*a));
		rrotate(&(*b));
		return (true);
	}
	return (false);
}

void	findOp(t_stack *a, t_stack *b, char *op)
{
	if (findSwap(a, b, op) || findPush(a, b, op))
		return ;
	if (findRotate(a, b, op) || findRevRotate(a, b, op))
		return ;
	write(1, "invalid instruction: ", 21);
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
	write(1, "KO\n", 3);
	exit(1);
}
