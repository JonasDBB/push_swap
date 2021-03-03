#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack {
	size_t	size;
	size_t	currentSize;
	int		*stack;
}				t_stack;

bool	isAllDigit(char *s);
void	setupStacks(t_stack *a, t_stack *b, char **av, bool debug);
void	cleanupStacks(int **a, int **b);
void	printStacks(t_stack a, t_stack b);
bool	isSorted(t_stack s);

void	swapTop(t_stack *s);
void	push(t_stack *dst, t_stack *src);
void	rotate(t_stack *s);
void	rrotate(t_stack *s);
void	findOp(t_stack *a, t_stack *b, char *op);

#endif
