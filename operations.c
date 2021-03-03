#include "push_swap.h"

void	swapElems(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swapTop(t_stack *s)
{
	if (s->currentSize <= 1)
		return ;
	swapElems(&(s->stack[s->currentSize - 1]), &(s->stack[s->currentSize - 2]));
}

void	push(t_stack *dst, t_stack *src)
{
	if (src->currentSize == 0)
		return ;
	dst->stack[dst->currentSize] = src->stack[src->currentSize - 1];
	dst->currentSize++;
	src->currentSize--;
}

void	rotate(t_stack *s)
{
	int	first;
	int	i;

	if (s->currentSize <= 1)
		return ;
	first = s->stack[0];
	i = 0;
	while (i < s->currentSize - 1)
	{
		s->stack[i] = s->stack[i + 1];
		i++;
	}
	s->stack[i] = first;
}

void	rrotate(t_stack *s)
{
	int	last;
	int	i;

	if (s->currentSize <= 1)
		return ;
	last = s->stack[s->currentSize - 1];
	i = s->currentSize - 1;
	while (i > 0)
	{
		s->stack[i] = s->stack[i - 1];
		i--;
	}
	s->stack[i] = last;
}
