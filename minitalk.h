/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:52:01 by rmaanane          #+#    #+#             */
/*   Updated: 2025/04/05 11:48:50 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

// client
void	check_digit(char *str);
long	ft_atol(char *str);
void	send_char(char c, int pid);
void	send_string(char *s, int pid);

// server
void	ft_putnbr(int n);
void	signal_handler(int sig);

#endif
