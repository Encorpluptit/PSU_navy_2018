/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Header for map_management and map_parser.
*/

#ifndef _MAP_MANAGEMENT_
#define _MAP_MANAGEMENT_

//<===============================================>
//<===============================================>
// Neccessary includes.
#include "essentials.h"
#include <inttypes.h>

//<===============================================>
//<===============================================>
// Define const and used macro for parser.
UNUSED static const uint8_t MAP_SIZE = 8;
UNUSED static const char *BOARD_FIRST_LINE = " |ABCDEFGH\n";
UNUSED static const char *BOARD_FRAME = "-+--------\n";

#define FILL_BLANK_LINE                         \
    for (uint8_t j = 0; j < MAP_SIZE; ++j)      \
        *(*(map + i) + j) = '.';                \
    *(*(map + i) + MAP_SIZE) = '\0';            \

#endif /* _MAP_MANAGEMENT_ */
