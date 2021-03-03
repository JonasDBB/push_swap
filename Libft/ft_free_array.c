#include <stdlib.h>

void	*ft_freearray(void **result, int i)
{
	while (i >= 0)
	{
		if (result[i])
			free(result[i]);
		i--;
	}
	if (result)
		free(result);
	return (NULL);
}
