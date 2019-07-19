/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Player one game initialisation.
*/

#include <signal.h>
#include "essentials.h"
#include "printf.h"

static int wait_for_player_two(void);
static void make_connection(int signum, siginfo_t *si, void *ucontext);

int player_one_entry(char *map_path)
{
    pid_t pid = getpid();
    my_printf("my_pid:  %d\n", pid);
    wait_for_player_two();
    return SUCCESS;
}

static int wait_for_player_two(void)
{
    struct sigaction sa;

    sa.sa_sigaction = make_connection;
    sa.sa_flags = SA_SIGINFO;
//    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR2, &sa, NULL);
    for (int i = 1; i;) {
        pause();
        i = 0;
    }
}

static void make_connection(int signum, siginfo_t *si, void *ucontext)
{
    if (signum == SIGUSR2) {
        my_printf("Signal recu\n");
        return;
    }
}
