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

#include "client.h"
#include <stdio.h>

void	handle_error(int n)
{
	if (n == -1)
		ft_putstr("usage: ./client server_pid message\n");
	if (n == -2)
		ft_putstr("error: server with the given process ID is not available\n");
	if (n == -3)
		ft_putstr("error: empty message - nothing to send\n");
	if (n == -4)
		ft_putstr("error: wrong process ID\n");
	if (n == -5)
		ft_putstr("error: couldn't establish connection with server\n");
	if (n == -6)
		ft_putstr("error: connection with server is lost\n");
	exit(-n);
}

void	check_signal(int sig)
{
	static int	prev_sig = SIGUSR2;

	if (prev_sig != sig)
		g_server_received = 1;
	prev_sig = sig;
}

void	handle_connection(int pid, int *j, char *c)
{
	signal(SIGUSR1, &check_signal);
	signal(SIGUSR2, &check_signal);
	if (g_server_received == 1)
	{
		(*c) = (*c) << 1;
		(*j)++;
	}
	while (sleep(2) == 0)
		if (kill(pid, 0) == -1)
			handle_error(-6);
}

void	send_message(int pid, char *s, int len)
{
	int				i;
	int				j;
	unsigned char	max;

	i = 0;
	j = 0;
	max = 128;
	while (i <= len)
	{
		j = 0;
		while (j < 8)
		{
			usleep(20);
			if (s[i] & max)
				kill(pid, SIGUSR1);
			else if (!(s[i] & max))
				kill(pid, SIGUSR2);
			handle_connection(pid, &j, &s[i]);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		pid;
	int		len;

	server_received = 1;
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		if (pid < 1)
			handle_error(-4);
		if (kill(pid, 0) == -1)
			handle_error(-2);
		len = (int)ft_strlen(argv[2]);
		if (len < 1)
			handle_error(-3);
		send_message(pid, argv[2], len);
	}
	else
		handle_error(-1);
	return (0);
}
