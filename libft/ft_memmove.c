/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:29:33 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 11:55:31 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned long int	i;
	char				tmp[1];
	char				*tmp_dst;
	char				*tmp_src;

	i = 0;
	if (&dst[0] < &src[0])
		while (i < n)
		{
			tmp_dst = &dst[i];
			tmp_src = (char *)&src[i];
			tmp[0] = *tmp_src;
			*tmp_dst = tmp[0];
			i++;
		}
	else
		while (i < n)
		{
			n--;
			tmp_dst = &dst[n];
			tmp_src = (char *)&src[n];
			tmp[0] = *tmp_src;
			*tmp_dst = tmp[0];
		}
	return (dst);
}
