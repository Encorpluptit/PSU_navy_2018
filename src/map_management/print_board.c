/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Source file for printing map and enemy map..
*/

#include "essentials.h"
#include "map_management.h"
#include "printf.h"

static int print_map(char **map);

int print_board(char **map, char **enemy_map)
{
    my_printf("my postions:\n");
    print_map(map);
    my_printf("\nenemy's positions:\n");
    print_map(enemy_map);
    return SUCCESS;
}

static int print_map(char **map)
{
    my_printf(BOARD_FIRST_LINE);
    my_printf(BOARD_FRAME);
    for (uint8_t i = 0; i < MAP_SIZE && *(map + i); ++i) {
        my_printf("%u|", i + 1);
        my_printf("%s\n", *(map + i));
    }
}
