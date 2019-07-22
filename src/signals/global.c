/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Source file with singleton(s) that keep in memory value needed
*/

#include "global.h"

int signal_info(uint32_t value, global_flag_t flag)
{
    static uint32_t value_save = 0;

    if (flag == SET)
        value_save = value;
    if (flag == GET)
        return value_save;
    if (flag == RESET)
        value_save = 0;
    return value_save;
}

bool stop_signal(global_flag_t flag)
{
    static bool stop_save = false;

    if (flag == SET)
        stop_save = true;
    if (flag == GET)
        return stop_save;
    if (flag == RESET)
        stop_save = false;
    return stop_save;
}
