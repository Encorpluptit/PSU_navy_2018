/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Unit test soource file for globals source file fcts.
*/

#include "tests_run.h"
#include "global.h"

Test(signal_info_set, test_signal_info_set)
{
    cr_assert_eq(SET_GLOBAL(5), 5, "res: %d", GET_GLOBAL);
    RESET_GLOBAL;
}

Test(signal_info_get, test_signal_info_get)
{
    SET_GLOBAL(4);
    cr_assert_eq(GET_GLOBAL, 4, "res: %d", GET_GLOBAL);
    RESET_GLOBAL;
}

Test(signal_info_reset, test_signal_info_reset)
{
    SET_GLOBAL(4);
    RESET_GLOBAL;
    cr_assert_eq(GET_GLOBAL, 0, "res: %d", GET_GLOBAL);
    RESET_GLOBAL;
}

Test(signal_info, test_stop_signal_set)
{
    SET_STOP;
    cr_assert_eq(GET_STOP, true, "res: %d", GET_STOP);
    RESET_STOP;
}

Test(signal_info, test_stop_signal_reset)
{
    SET_STOP;
    RESET_STOP;
    cr_assert_eq(GET_STOP, false, "res: %d", GET_STOP);
    RESET_STOP;
}
