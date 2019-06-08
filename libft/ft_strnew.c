/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:22:27 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 12:26:59 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(unsigned long int size)
{
	char				*mem;
	unsigned long int	i;

	i = 0;
	mem = 0;
	if ((mem = (char*)malloc(sizeof(char) * (size + 1))))
		while (i < (size + 1))
		{
			mem[i] = '\0';
			i++;
		}
	return (mem);
}
