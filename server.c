/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:48:40 by rmaanane          #+#    #+#             */
/*   Updated: 2025/04/05 09:48:42 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + 48;
	write(1, &c, 1);
}

void	signal_handler(int sig)
{
	static int	i = 7;
	static char	c = 0;

	if (sig == SIGUSR2)
		c = c | (1 << i);
	i--;
	if (i == -1)
	{
		write(1, &c, 1);
		c = 0;
		i = 7;
	}
}

int	main(void)
{
	write(1, "Pid : ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
