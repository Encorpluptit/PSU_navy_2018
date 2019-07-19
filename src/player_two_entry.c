/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** player two game initialisation.
*/

#include <signal.h>
#include "essentials.h"
#include "navy.h"
#include "printf.h"

static int connect_to_player_one(int ennemy_pid);

int player_two_entry(char *str_pid, char *map_path)
{
    int pid = -1;

    if (my_str_isnum(str_pid) == ERROR)
        return ERROR;
    connect_to_player_one(my_atoi(str_pid));
    return SUCCESS;
}

static int connect_to_player_one(int ennemy_pid)
{
//    struct sigaction sa;

    /* sa.sa_sigaction = make_connection; */
    /* sa.sa_flags = SA_SIGINFO; */
//    sigemptyset(&sa.sa_mask);
    kill(ennemy_pid, SIGUSR2);
    /* sigaction(SIGUSR2, &sa, NULL); */
    /* while (1) { */
    /*     pause(); */
    /* } */
}

static void make_connection(int signum, siginfo_t *si, void *ucontext)
{
    if (signum == SIGUSR2) {
//        my_printf("Signal %s received from %ld\n", strsignal(signum), si->si_pid);
        return;
    }
}
