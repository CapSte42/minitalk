/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:51:09 by smontuor          #+#    #+#             */
/*   Updated: 2024/02/21 19:11:37 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				bit_itr = -1;
	static unsigned char	c;

	(void)ucontent;
	if (bit_itr < 0)
		bit_itr = 7;
	if (signum == SIGUSR1)
		c |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			ft_printf(2, "Server failed to send SIGUSR2");
		return ;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_printf(2, "Failed to send SIGUSR1");
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	ft_memset(&sa_newsig, 0, sizeof(sa_newsig));
	sa_newsig.sa_sigaction = &handle_sigusr;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		ft_printf(2, "Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		ft_printf(2, "Failed to change SIGUSR2's behavior");
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_printf(1, "SERVER PID = %d\n\n", server_pid);
	config_signals();
	while (1)
		;
	return (0);
}
