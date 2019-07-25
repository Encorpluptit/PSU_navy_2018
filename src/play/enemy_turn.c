/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Source file for managing enemy_turn
*/

#include <signal.h>
#include "essentials.h"
#include "navy.h"
#include "printf.h"

static pos_t wait_for_enemy(void);
static bool check_hit(pos_t pos, char **map);
static int check_map(navy_t *navy, game_t *game);

uint8_t enemy_turn(navy_t *navy, game_t *game)
{
    pos_t pos;

    if (navy->player_id == SIGUSR2)
        print_board(navy->map, navy->enemy_map);
    my_printf("waiting for enemy's attack...\n");
    if (receive_info() == STOP_GAME) {
        game->play = false;
        print_board(navy->map, navy->enemy_map);
        return ERROR;
    }
    pos = wait_for_enemy();
    if (check_hit(pos, navy->map))
        check_map(navy, game);
    else
        send_info(navy->enemy_pid, MISSED);
//    game->play = false;

//    usleep(100000);
    game->turn = true;
    return game->win;
}

static pos_t wait_for_enemy(void)
{
    pos_t pos;

    pos.col = receive_info();
    pos.line = receive_info();
    return (pos);
}

static bool check_hit(pos_t pos, char **map)
{
    if (map[pos.line][pos.col] == '.' || map[pos.line][pos.col] == 'o') {
        map[pos.line][pos.col] = 'o';
        my_printf("%c%c:  %s\n", LETTER(pos.col), NUMBER(pos.line), "missed\n");
        return false;
    } else if (map[pos.line][pos.col] == 'x') {
        my_printf("%c%c:  %s\n", LETTER(pos.col), NUMBER(pos.line), "missed\n");
    } else {
        map[pos.line][pos.col] = 'x';
        my_printf("%c%c:  %s\n", LETTER(pos.col), NUMBER(pos.line), "hit\n");
        return true;
    }
}

static int check_map(navy_t *navy, game_t *game)
{
    bool end = true;
    char *line = NULL;

    for (uint8_t i = 0; *(navy->map + i) && end; ++i) {
        line = *(navy->map + i);
        for (; *line && end; ++line)
            COUNT(*line) ? end = false : 0;
    }
    if (!end)
        send_info(navy->enemy_pid, HIT);
    else {
        send_info(navy->enemy_pid, STOP_GAME);
        print_board(navy->map, navy->enemy_map);
        game->play = false;
    }
    return SUCCESS;
}
