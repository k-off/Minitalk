/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 09:11:09 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/16 09:44:34 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst && del)
	{
		while (*alst)
		{
			tmp = alst[0]->next;
			(*del)(alst[0]->content, alst[0]->content_size);
			free(alst[0]);
			alst[0] = tmp;
		}
		*alst = 0;
	}
}
