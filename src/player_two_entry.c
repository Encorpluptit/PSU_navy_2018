/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** player two game initialisation.
*/

#include <signal.h>
#include "essentials.h"
#include "navy.h"
#include "global.h"
#include "printf.h"

static int connect_to_player_one(int ennemy_pid);
static void make_connection(int signum, siginfo_t *si, void *ucontext);

int player_two_entry(char *str_pid, char *map_path)
{
    char **map = parser_entry(map_path);
    pid_t pid = getpid();
    int enemy_pid = -1;

    if (!map || my_str_isnum(str_pid) == ERROR)
        return ERROR;
    my_printf("my_pid:  %d\n", pid);
    enemy_pid = connect_to_player_one(my_atoi(str_pid));
    my_printf("%d\n", enemy_pid);
    return SUCCESS;
}

static int connect_to_player_one(int ennemy_pid)
{
    struct sigaction sa;
    pid_t enemy_pid = -1;

    sa.sa_sigaction = make_connection;
    sa.sa_flags = SA_SIGINFO;
//    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1) {
        kill(ennemy_pid, SIGUSR2);
        pause();
        if ((enemy_pid = GET_GLOBAL)) {
//            pause();
            break;
        }
    }
    return enemy_pid;
}

static void make_connection(int signum, siginfo_t *si, void *ucontext)
{
    if (signum == SIGUSR1) {
        my_printf("successfully connected\n");
        SET_GLOBAL(si->si_pid);
        return;
    }
}
