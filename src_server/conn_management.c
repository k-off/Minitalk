/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 10:38:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/04/18 10:38:00 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static t_client	*new_client(int pid)
{
	t_client	*new;

	new = NULL;
	new = (t_client*)ft_memalloc(sizeof(t_client));
	if (new == NULL)
	{
		ft_putstr("error: malloc new client failed\n");
		exit(1);
	}
	new->pid = pid;
	new->send_sig = SIGUSR2;
	return (new);
}

t_client		*get_client(pid_t pid)
{
	t_client *client;
	t_client *prev;

	client = g_client;
	prev = NULL;
	if (client)
	{
		while (client && client->pid != pid)
		{
			prev = client;
			client = client->next;
		}
		if (client == NULL)
		{
			prev->next = new_client(pid);
			client = prev->next;
		}
	}
	else
	{
		client = new_client(pid);
		g_client = client;
	}
	return (client);
}

void			free_client(pid_t pid)
{
	t_client *client;
	t_client *prev;

	client = g_client;
	prev = NULL;
	while (client && client->pid != pid)
	{
		prev = client;
		client = client->next;
	}
	if (client)
	{
		if (client != g_client)
			prev->next = client->next;
		else
			g_client = client->next;
		free(client);
	}
}
