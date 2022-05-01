#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void handlerSignals(int sig);
int flag = 0;
int signals = 0;

int main()
{
    printf("PID = %d\n", getpid());

    if(signal(SIGUSR1, handlerSignals) == SIG_ERR) {
        printf("[SIGUSR1] : ERROR\n");
        return 1;
    }

    if(signal(SIGUSR2, handlerSignals) == SIG_ERR) {
        printf("[SIGUSR2] : ERROR\n");
        return 1;
    }

    while(flag != 1) {
        pause();
    }

    return 0;
}

void handlerSignals(int sig)
{
    if(sig == SIGUSR1) {
        signals++;
        printf("SIGUSR1 signal recieved!\n");
    }

    else if(sig == SIGUSR2) {
        printf("\nSIGUSR2 signal: %d\n", signals);
        signal(SIGUSR2, SIG_DFL);
        flag = 1;
    }
}
