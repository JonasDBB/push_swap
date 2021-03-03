/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 12:26:57 by jbennink      #+#    #+#                 */
/*   Updated: 2020/06/25 11:15:21 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	ft_getnbr(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	if (s[i - 1] == c)
		j -= 1;
	return (j);
}

static char	*ft_addword(char const *s, char *result, char c)
{
	int	j;

	j = 0;
	while (s[j] && s[j] != c)
	{
		result[j] = s[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

static char	**TERN(char boool, char **first, char **second)
{
	if (boool)
		return (first);
	return (second);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	result = TERN((!s), NULL, malloc(sizeof(char *) * (ft_getnbr(s, c) + 1)));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			break ;
		result[i] = (char *)malloc(ft_len(s, c) + 1);
		if (!result[i])
			return (ft_freearray((void**)result, i));
		result[i] = ft_addword(s, result[i], c);
		while (*s != c && *s)
			s++;
		i++;
	}
	result[i] = NULL;
	return (result);
}
