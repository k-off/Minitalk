/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 10:38:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/04/18 10:38:00 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <sys/types.h>
# include "../libft/libft.h"

typedef struct		s_data
{
	int				bit_nr;
	int				len;
	char			s[1001];
}					t_data;

typedef struct		s_client
{
	int				pid;
	int				send_sig;
	t_data			data;
	struct s_client	*next;
}					t_client;

t_client			*g_client;

int					main(void);
void				retry_clients(void);
void				handle_signal(int recv_sig, siginfo_t *info, void *context);
void				add_bit(t_client *client, int received_signal);
void				print_message(t_client *client);
t_client			*get_client(pid_t pid);
void				free_client(pid_t pid);

#endif
