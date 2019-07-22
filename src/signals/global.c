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
    if (flag == RETURN)
        return value_save;
    if (flag == RESET)
        value_save = 0;
    return value_save;
}
