/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Header for singleton management.
*/

#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <inttypes.h>

typedef enum {
    SET,
    RETURN,
    RESET,
} global_flag_t;

int signal_info(uint32_t value, global_flag_t flag);

#define SET_GLOBAL(value) (signal_info(value, SET))
#define GET_GLOBAL (signal_info(0u, RETURN))
#define RESET_GLOBAL (signal_info(0u, RESET))

#endif /* _GLOBAL_H_ */
