/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 09:27:42 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 10:26:51 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char *ptr;

	ptr = &s[n - 1];
	while (n > 0)
	{
		*ptr = c;
		n--;
		ptr--;
	}
	return (s);
}
