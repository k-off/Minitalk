/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 17:03:52 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 12:00:41 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char n;

	n = '\n';
	if (s != 0 && fd > 0)
	{
		while (s[0] != '\0')
		{
			write(fd, s, 1);
			s++;
		}
		write(fd, &n, 1);
	}
}
