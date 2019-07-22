/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Header for singleton management.
*/

#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <inttypes.h>
#include <stdbool.h>

typedef struct sigaction siga_t;

typedef enum {
    SET,
    GET,
    RESET,
} global_flag_t;

int signal_info(uint32_t value, global_flag_t flag);
bool stop_signal(global_flag_t flag);

#define SET_GLOBAL(value) (signal_info(value, SET))
#define GET_GLOBAL (signal_info(0u, GET))
#define RESET_GLOBAL (signal_info(0u, RESET))

#define SET_STOP (stop_signal(SET))
#define GET_STOP (stop_signal(GET))
#define RESET_STOP (stop_signal(RESET))

#endif /* _GLOBAL_H_ */
