/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Source file for communication by signals (send/receive).
*/

#include <signal.h>
#include "global.h"

#include "printf.h"

static void catch_signal(int signum);

int send_info(uint32_t enemy_pid, uint8_t info)
{
    usleep(500);
    for (; info; --info) {
        usleep(500);
        kill(enemy_pid, SIGUSR1);
    }
    usleep(500);
    kill(enemy_pid, SIGUSR2);
}

int receive_info(void)
{
    siga_t sa = (siga_t) {.sa_handler = catch_signal};

    RESET_STOP;
    RESET_GLOBAL;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (!GET_STOP)
        pause();
    return (GET_GLOBAL);
}

static void catch_signal(int signum)
{
    if (signum == SIGUSR1)
        SET_GLOBAL(GET_GLOBAL + 1);
    if (signum == SIGUSR2)
        SET_STOP;
}
