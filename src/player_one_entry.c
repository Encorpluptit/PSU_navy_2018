/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Player one game initialisation.
*/

#include <signal.h>
#include "essentials.h"
#include "navy.h"
#include "global.h"
#include "printf.h"

static int wait_for_player_two(void);
static void make_connection(int signum, siginfo_t *si, void *ucontext);

int player_one_entry(char *map_path)
{
    char **map = parser_entry(map_path);
    pid_t pid = getpid();
    pid_t enemy_pid = -1;
    /* navy_t game; */

    if (!map)
        return ERROR;
    my_printf("my_pid:  %d\n", pid);
    enemy_pid = wait_for_player_two();
    my_printf("%d\n", enemy_pid);
    /* if (!(game = fill_game_info(map, pid, GET_GLOBAL))) */
    /*     return ERROR; */
    /* return (launch_game(game, flag_player)); */
    return SUCCESS;
}

static int wait_for_player_two(void)
{
    struct sigaction sa;
    pid_t enemy_pid = -1;

    sa.sa_sigaction = make_connection;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    my_printf("waiting for enemy connection...\n\n");
    while (1) {
        pause();
        if ((enemy_pid = GET_GLOBAL)) {
            kill(enemy_pid, SIGUSR1);
            break;
        }
    }
    return enemy_pid;
}

static void make_connection(int signum, siginfo_t *si, void *ucontext)
{
    if (signum == SIGUSR2) {
        my_printf("enemy connected\n");
        SET_GLOBAL(si->si_pid);
        return;
    }
}
