/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Header for the entire project.
*/

#ifndef _NAVY_H_
#define _NAVY_H_

//<===============================================>
//<===============================================>
// Necessary includes.
#include <inttypes.h>

//<===============================================>
//<===============================================>
// navy stucture.

typedef struct navy_s {
    char **map;
    char **enemy_map;
    uint32_t pid;
    uint32_t enememy_pid;
    uint8_t player_id;
} navy_t;

//<===============================================>
//<===============================================>
// Project functions prototypes.

//<===============================================>
// LIB prototypes.
int my_str_isnum(char const *str);
int my_atoi(char const * const str);

//<===============================================>
// map_parser folder.
char **parser_entry(char *map_path);

//<===============================================>
// player_one_entry.c.
int player_one_entry(char *map_path);

//<===============================================>
// player_two_entry.c.
int player_two_entry(char *str_pid, char *map_path);

#endif /* _NAVY_H_ */
