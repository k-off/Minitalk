/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 10:49:53 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:46:53 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_filin(char const *s, char *dst, int start, int stop)
{
	int i;

	i = 0;
	if ((stop >= start && (dst = (char*)malloc(sizeof(char) *
		(stop - start + 2)))) || (dst = (char*)malloc(1)))
	{
		while (start <= stop)
			dst[i++] = s[start++];
		dst[i] = '\0';
	}
	return (dst);
}

char		*ft_strtrim(char const *s)
{
	int		len;
	int		start;
	int		stop;
	char	*dst;

	len = 0;
	start = 0;
	dst = 0;
	if (s != 0)
	{
		while (s[len] != '\0')
			len++;
		stop = len - 1;
		while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			&& start < len)
			start++;
		while ((s[stop] == ' ' || s[stop] == '\n' || s[stop] == '\t')
			&& stop > 0)
			stop--;
		dst = ft_filin(s, dst, start, stop);
	}
	return (dst);
}
