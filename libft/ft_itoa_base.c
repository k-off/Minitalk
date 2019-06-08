/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 15:19:28 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 16:04:06 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_remal(char *str, int isneg)
{
	int		i;
	char	*res;

	res = 0;
	if (isneg < 0)
		*str = '-';
	while (!(*str == 45 || (*str > 47 && *str < 58) ||
		(*str > 64 && *str < 71)))
		str++;
	i = 0;
	while (str[i] != '\0')
		i++;
	if ((res = (char*)malloc(sizeof(char) * (i + 1))))
	{
		i = 0;
		while (str[i] != '\0')
		{
			res[i] = str[i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (0);
}

char		*ft_itoa_base(long int n, int base)
{
	char	*str;
	int		isneg;
	char	*xnbrs;

	xnbrs = "0123456789ABCDEF";
	n = (int)n;
	if (!(str = (char*)malloc(32)) || base < 2 || base > 16)
		return (0);
	str += 31;
	isneg = 1;
	if (n < 0)
	{
		if (base == 10)
			isneg = -1;
		n = -n;
	}
	*str-- = '\0';
	if (n == 0)
		*str-- = '0';
	while (n > 0)
	{
		*str-- = xnbrs[n % base];
		n /= base;
	}
	return (ft_remal(str, isneg));
}
