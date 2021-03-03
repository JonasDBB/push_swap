/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:28:42 by jbennink      #+#    #+#                 */
/*   Updated: 2020/06/03 14:14:31 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	FAK(size_t len, char *s, char *d)
{
	while (len > 0)
	{
		d[len - 1] = s[len - 1];
		len--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	if (&d[i] >= &s[i] && &s[len - i] > &d[i])
	{
		FAK(len, s, d);
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
