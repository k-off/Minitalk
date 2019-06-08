/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:22:27 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 12:09:43 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	char	*c;
	size_t	i;

	if (size == 0)
		return (0);
	i = 0;
	mem = 0;
	if ((mem = malloc(size)))
		while (i < size)
		{
			c = &mem[i];
			*c = '\0';
			i++;
		}
	return (mem);
}
