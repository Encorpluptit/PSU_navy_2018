/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** header for map_parser module.
*/

#ifndef _MAP_PARSER_
#define _MAP_PARSER_

//<===============================================>
//<===============================================>
// Neccessary includes.
#include <inttypes.h>

//<===============================================>
//<===============================================>
// Define const and used macro for parser.
#define BOAT_NB(c, index) (c == (index + '0'))
#define UPPERCASE(c) (c >= 'A' && c <= 'H')
#define CASE_NB(c) (c >= '1' && c <= '8')
#define ABS(x) ((x >= 0) ? x : -x)
#define CHAR_TO_INDEX(c) (c - 'A')
#define NB_TO_INDEX(c) (c - '0' - 1)

static const int8_t FILE_ERROR = -1;

//<===============================================>
//<===============================================>
// Functions prototypes.

//<===============================================>
// LIB prototypes.
size_t my_strlen(char const *str);
char *get_next_line(int fd);
int my_str_isnum(char const *str);

//<===============================================>
// map_management folder prototypes.
int free_map(char **map);
char **create_map(void);

//<===============================================>
// map_error_synthax.c prototypes.
int check_map_error(int fd);

//<===============================================>
// read_map.c prototypes.
char **read_map(int fd);

#endif /* _MAP_PARSER_ */
