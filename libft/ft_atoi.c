/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:44:45 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 18:01:27 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	int				i;
	long int		res;
	int				is_first;
	int				is_negative;

	i = 0;
	res = 0;
	is_first = 1;
	is_negative = 1;
	while (!(str[i] == '\0' || is_first == 0) && (str[i] == ' ' ||
	((str[i] == '-' || str[i] == '+') && (str[i + 1] > 47 && str[i + 1] < 58))
	|| str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r'
	|| str[i] == '\f' || (str[i] > 47 && str[i] < 58)))
	{
		if (str[i] > 47 && str[i] < 58)
		{
			res = (int)(res * 10 + (str[i] - '0'));
			if (i > 0 && str[i - 1] == '-')
				is_negative *= -1;
			if (!(str[i + 1] > 47 && str[i + 1] < 58))
				is_first = 0;
		}
		i++;
	}
	return ((int)(res * is_negative));
}
