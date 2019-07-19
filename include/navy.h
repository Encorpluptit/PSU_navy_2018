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
