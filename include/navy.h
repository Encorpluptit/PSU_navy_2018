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
#include <stdbool.h>

//<===============================================>
//<===============================================>
// navy stuctures.

typedef struct game_s {
    uint8_t turn : 1;
    uint8_t play : 1;
    uint8_t win : 1;
} game_t;

typedef struct pos_s {
    uint8_t line;
    uint8_t col;
} pos_t;

typedef struct navy_s {
    char **map;
    char **enemy_map;
    uint32_t pid;
    uint32_t enemy_pid;
    uint8_t player_id;
} navy_t;

typedef enum {
    MISSED,
    HIT,
    STOP_GAME
} hit_t;

static const uint8_t QUIT = 2;

//<===============================================>
//<===============================================>
// Maccro for lulz.
#define LETTER(x) (x + 'A')
#define NUMBER(x) (x + '1')
#define COUNT(x) (x >= '2' && x <= '5')

#define IS_LETTER(x) (x >= 'A' && x <= 'H')
#define IS_NUMBER(x) (x >= '1' && x <= '8')

//<===============================================>
//<===============================================>
// Project functions prototypes.

//<===============================================>
// LIB prototypes.
int my_str_isnum(char const *str);
size_t my_strlen(char const *str);
int my_atoi(char const * const str);
char *get_next_line(int fd);

//<===============================================>
// map_parser folder.
char **parser_entry(char *map_path);

//<===============================================>
// player_entry.c.
int player_entry(char *str_pid, char *map_path);

//<===============================================>
// global.c.
int send_info(uint32_t enemy_pid, uint8_t info);
int receive_info(void);

//<===============================================>
// create_map.c.
char **create_map(void);

//<===============================================>
// play_navy.c.
int play_navy(navy_t *navy);

//<===============================================>
// player_turn.c.
uint8_t player_turn(navy_t *navy, game_t *game);

//<===============================================>
// player_turn.c.
uint8_t enemy_turn(navy_t *navy, game_t *game);

//<===============================================>
// free_map.c.
int free_board(char **map, char **enemy_map, int return_code);

//<===============================================>
// print_board.c.
int print_board(char **map, char **enemy_map);

#endif /* _NAVY_H_ */
