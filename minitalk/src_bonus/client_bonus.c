/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:15:39 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/21 19:21:41 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	g_message_received;

void	args_check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf(2, "Invalid number of arguments");
		exit (1);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
		{
			ft_printf(2, "Invalid PID");
			exit (1);
		}
	}
	if (*argv[2] == 0)
	{
		ft_printf(2, "Invalid message (empty)");
		exit (1);
	}
}

void	send_msg(pid_t sv_pid, char *msg)
{
	unsigned char	c;
	int				nbr_bits;

	while (*msg)
	{
		c = *msg;
		nbr_bits = 8;
		while (nbr_bits--)
		{
			if (c & 0b10000000)
				kill(sv_pid, SIGUSR1);
			else
				kill(sv_pid, SIGUSR2);
			usleep(50);
			c <<= 1;
		}
		msg++;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
	{
		write(1, "Character has been sucessfully receieved!\n", 42);
		g_message_received++;
	}
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	ft_memset(&sa_newsig, 0, sizeof(sa_newsig));
	sa_newsig.sa_handler = &sig_handler;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		ft_printf(2, "Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		ft_printf(2, "Failed to change SIGUSR2's behavior");
}

int	main(int argc, char **argv)
{
	pid_t		sv_pid;
	int			e;

	e = 0;
	args_check(argc, argv);
	sv_pid = ft_atoi(argv[1], &e);
	ft_printf(1, "CLIENT PID = %d\n", getpid());
	config_signals();
	send_msg(sv_pid, argv[2]);
	while (g_message_received < ft_strlen(argv[2]))
		;
	return (0);
}
