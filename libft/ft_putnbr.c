/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 17:38:53 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/17 19:05:35 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int				i;
	char			s[12];
	int				isneg;
	long long int	m;

	m = n;
	i = 12;
	s[--i] = '\0';
	isneg = 1;
	if (m < 0)
	{
		m = -m;
		isneg = -1;
	}
	if (m == 0)
		s[--i] = '0';
	while (m != 0 && i > 0)
	{
		s[--i] = (m % 10) + '0';
		m /= 10;
	}
	if (isneg == -1)
		s[--i] = '-';
	while (i < 11)
		write(1, &s[i++], 1);
}
