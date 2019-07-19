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
#include <inttypes.h>

//<===============================================>
//<===============================================>
// Define const and used macro for parser.
static const uint8_t MAP_SIZE = 8;

#define FILL_BLANK_LINE                         \
    for (uint8_t j = 0; j < MAP_SIZE; ++j)      \
        *(*(map + i) + j) = '.';                \
    *(*(map + i) + MAP_SIZE) = '\0';            \

#endif /* _MAP_MANAGEMENT_ */
