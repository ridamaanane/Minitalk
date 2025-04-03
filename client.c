#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;
    int sign = 1;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - 48;
        i++; 
    }
    return (result * sign);
}
void send_char(char c, int pid)
{
    int i = 7;

    while (i >= 0)
    {
	    kill(pid, c & (1 << i) ? SIGUSR2 : SIGUSR1);
	    usleep(1000);
	    i--;
    }
}

void send_string(char *s, int pid)
{
	while (*s)
		send_char(*s++, pid);
}


int main(int ac, char **av)
{
    int pid;
    //int sig;
    if (ac == 3)
    {
	    pid = ft_atoi(av[1]);
	    send_string(av[2], pid);

    }
}
