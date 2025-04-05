/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:48:32 by rmaanane          #+#    #+#             */
/*   Updated: 2025/04/05 11:46:27 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write(1, "❌ PID must contain only numbers!\n", 36);
			exit(1);
		}
		i++;
	}
}

long	ft_atol(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		check_digit(str);
		result = result * 10 + (str[i] - '0');
		if (result >= INT_MAX)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (result);
}

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "Error\n", 6);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "Error\n", 6);
				exit(1);
			}
		}
		usleep(800);
		i--;
	}
}

void	send_string(char *s, int pid)
{
	while (*s)
		send_char(*s++, pid);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atol(av[1]);
		send_string(av[2], pid);
	}
	else
		write(1, "Error", 5);
}
