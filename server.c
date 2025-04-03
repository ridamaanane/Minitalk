#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig)
{
    static int i = 7;
    static char c = 0;

    if (sig == SIGUSR2)
        c = c | (1 << i);
    i--;
    if (i ==-1)
    {
        write(1, &c, 1);
        c = 0;
        i = 7;
    }
}

int main()
{
    printf("Number of pid -> [%d] \n", getpid());

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while (1)
        pause();
}
