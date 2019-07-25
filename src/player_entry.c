/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Source file for player entry in the prgrm.
*/

#include <signal.h>
#include "essentials.h"
#include "navy.h"
#include "global.h"
#include "printf.h"

static int connect_players(navy_t *navy, int str_pid);
static void connect(int signum, siginfo_t *si, void *ucontext);
static int make_connection(uint8_t player_id, int str_pid);
static navy_t fill_navy_struct(char *str_pid, char *map_path, pid_t pid);

int player_entry(char *str_pid, char *map_path)
{
    pid_t pid = getpid();
    int enemy_pid = -1;
    navy_t navy = fill_navy_struct(str_pid, map_path, pid);

    if (!(navy.map) || !(navy.enemy_map) ||
        (str_pid && (my_str_isnum(str_pid) == ERROR)))
        return free_board(navy.map, navy.enemy_map, 84);
    my_printf("my_pid:  %d\n", pid);
    if (navy.player_id == SIGUSR1)
        connect_players(&navy, 0u);
    else
        connect_players(&navy, my_atoi(str_pid));

    return play_navy(&navy);
}

static int connect_players(navy_t *navy, int str_pid)
{
    siga_t sa = (siga_t) {.sa_sigaction = connect, .sa_flags = SA_SIGINFO};
    pid_t enemy_pid = -1;

    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (make_connection(navy->player_id, str_pid) != SUCCESS);
    navy->enemy_pid = GET_GLOBAL;
    return SUCCESS;
}

static void connect(int signum, siginfo_t *si, void *ucontext)
{
    if (signum == SIGUSR1) {
        my_printf("successfully connected\n\n");
        SET_GLOBAL(si->si_pid);
        return;
    }
    if (signum == SIGUSR2) {
        my_printf("enemy connected\n\n");
        SET_GLOBAL(si->si_pid);
        return;
    }
}

static int make_connection(uint8_t player_id, int str_pid)
{
    pid_t enemy_pid = 0;

    if (player_id == SIGUSR1)
        my_printf("waiting for enemy connection...\n\n");
    else
        kill(str_pid, SIGUSR2);
    pause();
    if ((enemy_pid = GET_GLOBAL)) {
        if (player_id == SIGUSR1)
            kill(enemy_pid, SIGUSR1);
        return SUCCESS;
    }
    return ERROR;
}

static navy_t fill_navy_struct(char *str_pid, char *map_path, pid_t pid)
{
    navy_t navy;

    navy.map = parser_entry(map_path);
    navy.pid = pid;
    navy.enemy_map = create_map();
    navy.player_id = (!str_pid) ? SIGUSR1 : SIGUSR2;
    return (navy);
}
