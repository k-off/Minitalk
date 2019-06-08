/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 15:19:28 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/22 17:13:10 by pacovali      ########   odam.nl         */
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
	while (!(*str == 45 || (*str > 47 && *str < 58)))
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

static char	*ft_mmax(char *str)
{
	char	*max;
	int		i;

	i = 0;
	max = "2147483647";
	while (i < 10)
	{
		str[i] = *max;
		max++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		isneg;

	if (!(str = (char*)malloc(sizeof(char) * 12)))
		return (0);
	if (n == 2147483647)
		return (ft_mmax(str));
	str += 11;
	isneg = 1;
	*str-- = '\0';
	*str = '0';
	while (n > 0)
	{
		*str-- = n % 10 + '0';
		n /= 10;
	}
	while (n < 0)
	{
		isneg = -1;
		*str-- = -(n % 10) + '0';
		n /= 10;
	}
	return (ft_remal(str, isneg));
}
