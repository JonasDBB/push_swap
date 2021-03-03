#include <stdlib.h>

char	*gnl_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

void	buffer_set(char *orig, char *buffer)
{
	if (*buffer == '\n')
		buffer++;
	while (*buffer != '\0')
	{
		*orig = *buffer;
		buffer++;
		orig++;
	}
	*orig = '\0';
}

void	*ft_free(char **line)
{
	free(*line);
	return (NULL);
}
