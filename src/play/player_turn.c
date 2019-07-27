/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Source file for managing player turn.
*/

#include <signal.h>
#include "navy.h"
#include "essentials.h"
#include "printf.h"

static uint8_t hit_target(game_t *game, pos_t pos, navy_t *navy);
static pos_t get_user_input(navy_t *navy, game_t *game);
static bool check_user_synthax(char *input);
static void request_position(pos_t pos, navy_t *navy);

uint8_t player_turn(navy_t *navy, game_t *game)
{
    pos_t pos;

    if (navy->player_id == SIGUSR1)
        print_board(navy->map, navy->enemy_map);
    usleep(2000);
    if ((pos = get_user_input(navy, game)).line == ERROR)
            return QUIT;
    request_position(pos, navy);
    hit_target(game, pos, navy);
    game->turn = false;
    return game->win;
}

static void request_position(pos_t pos, navy_t *navy)
{
    usleep(2000);
    send_info(navy->enemy_pid, pos.col);
    send_info(navy->enemy_pid, pos.line);
}

static uint8_t hit_target(game_t *game, pos_t pos, navy_t *navy)
{
    uint8_t hit = receive_info();

    if (!hit) {
        if (navy->enemy_map[pos.line][pos.col] != 'x')
            navy->enemy_map[pos.line][pos.col] = 'o';
        my_printf("%c%c:  missed\n\n", pos.col + 'A', pos.line + '1');
    } else {
        navy->enemy_map[pos.line][pos.col] = 'x';
        my_printf("%c%c:  hit\n\n", pos.col + 'A', pos.line + '1');
        if (hit == STOP_GAME) {
            game->win = false;
            game->play = false;
            print_board(navy->map, navy->enemy_map);
        }
    }
    return SUCCESS;
}

static pos_t get_user_input(navy_t *navy, game_t *game)
{
    char *input = NULL;

    do {
        my_printf("attack:  ");
        input = get_next_line(0u);
        if (!input) {
            game->play = false;
            print_board(navy->map, navy->enemy_map);
            send_info(navy->enemy_pid, QUIT);
            return ((pos_t) {.line = ERROR, .col = ERROR});
        }
    } while (!check_user_synthax(input));
    send_info(navy->enemy_pid, MISSED);
    return ((pos_t) {.col = *input - 'A', .line = *(input + 1) - '1'});
}

static bool check_user_synthax(char *input)
{
    if (!input)
        return false;
    if (my_strlen(input) != 2) {
        my_printf("wrong position\n");
        return false;
    }
    if (IS_LETTER(*input) && IS_NUMBER(*(input + 1)))
        return true;
    else {
        my_printf("wrong position\n");
        return false;
    }
}
