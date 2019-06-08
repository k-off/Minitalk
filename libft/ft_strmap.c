/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:00:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/14 10:55:18 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *src, char (*f)(char))
{
	unsigned long int	i;
	unsigned long int	len;
	char				*dst;

	i = 0;
	len = 0;
	dst = 0;
	if (src != 0)
	{
		while (src[i] != '\0')
			i++;
		len = i;
		i = 0;
		if ((dst = (char *)malloc(sizeof(char) * (len + 1))))
		{
			while (i < len)
			{
				dst[i] = f(src[i]);
				i++;
			}
			dst[i] = '\0';
		}
	}
	return (dst);
}
