/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 14:06:22 by jbennink      #+#    #+#                 */
/*   Updated: 2020/06/03 14:13:09 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

size_t	FAKNORM(char *line, char *ret, size_t i)
{
	if (line != NULL)
	{
		while (line[i] != '\0')
		{
			ret[i] = line[i];
			i++;
		}
	}
	return (i);
}

static char	*join_line(char *line, char *buffer)
{
	char	*ret;
	char	*orig;
	size_t	i;

	orig = buffer;
	ret = (char *)malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	if (ret == NULL)
		return (ft_free(&line));
	i = 0;
	i = FAKNORM(line, ret, i);
	free(line);
	while (*buffer != '\0' && *buffer != '\n')
	{
		ret[i] = *buffer;
		buffer++;
		i++;
	}
	ret[i] = '\0';
	buffer_set(orig, buffer);
	return (ret);
}

static char	*CHARTERN(int boool, char *first, char *second)
{
	if (boool)
		return (first);
	return (second);
}

static int	INTTERN(int boool, int first, int second)
{
	if (boool)
		return (first);
	return (second);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		size;
	static char	buffer[BUFFER_SIZE + 1];
	int			ret;

	*line = NULL;
	ret = 0;
	while (ret == 0)
	{
		if (!*buffer)
		{
			size = read(fd, buffer, BUFFER_SIZE);
			if (size <= 0)
			{
				buffer[0] = '\0';
				ret = size;
				*line = CHARTERN((ret == 0), join_line(*line, buffer), NULL);
				break ;
			}
			buffer[size] = '\0';
		}
		ret = INTTERN(*(gnl_strchr(buffer, '\n')), 1, ret);
		*line = join_line(*line, buffer);
		ret = INTTERN((*line == NULL), -1, ret);
	}
	return (ret);
}
