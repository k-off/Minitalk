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

void		add_bit(t_client *client, int received_signal)
{
	if (received_signal == SIGUSR1)
		client->data.s[client->data.len] |= \
		(1 << (7 - client->data.bit_nr % 8));
	client->data.bit_nr++;
	if (client->data.bit_nr > 0 && client->data.bit_nr % 8 == 0)
	{
		if (client->data.s[client->data.len] == '\0')
		{
			ft_putstr(client->data.s);
			ft_putstr("\n");
			free_client(client->pid);
		}
		else if (client->data.len > 999)
			ft_putstr(client->data.s);
	}
	client->data.s[client->data.len + 1] = 0;
	client->data.len = (client->data.bit_nr / 8) % 1001;
}

void	handle_signal(int recv_sig, siginfo_t *info, void *context)
{
	t_client	*client;

	(void)context;
	client = get_client(info->si_pid);
	if (recv_sig == SIGUSR1)
		add_bit(client, SIGUSR1);
	else if (recv_sig == SIGUSR2)
		add_bit(client, SIGUSR2);
	usleep(10);
	if (client->send_sig == SIGUSR2)
		client->send_sig = SIGUSR1;
	else if (client->send_sig == SIGUSR1)
		client->send_sig = SIGUSR2;
	kill(client->pid, client->send_sig);
}

void	retry_clients(void)
{
	t_client *tmp;

	tmp = g_client;
	while (tmp)
	{
		if (kill(tmp->pid, 0) == -1)
		{
			ft_putstr("error: client ");
			ft_putnbr(tmp->pid);
			ft_putstr(" not available. Received part of message is:\n");
			ft_putstr(tmp->data.s);
			ft_putstr("\n");
			free_client(tmp->pid);
		}
		else
			kill(tmp->pid, tmp->send_sig);
		tmp = tmp->next;
	}
}

int		main(void)
{
	struct sigaction	siga;

	g_client = NULL;
	siga.sa_sigaction = &handle_signal;
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (1)
	{
		sigaction(SIGUSR1, &siga, NULL);
		sigaction(SIGUSR2, &siga, NULL);
		if (sleep(1) == 0)
			if (g_client)
				retry_clients();
	}
	return (0);
}
