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

int test(navy_t *navy, game_t *game, int turn)
{
    pos_t pos[] = {
        {.col = 0, .line = 2},
        {.col = 1, .line = 2},
        {.col = 3, .line = 3},
        {.col = 3, .line = 4},
        {.col = 3, .line = 5},
        {.col = 4, .line = 1},
        {.col = 5, .line = 1},
        {.col = 6, .line = 1},
        {.col = 7, .line = 1},
        {.col = 6, .line = 3},
        {.col = 6, .line = 4},
        {.col = 6, .line = 5},
        {.col = 6, .line = 6},
        {.col = 6, .line = 6},
        {.col = 6, .line = 6},
        {.col = 6, .line = 6},
        {.col = 6, .line = 6},
        {.col = 6, .line = 6},
        {.col = 6, .line = 6},
        {.col = 6, .line = 6},
        {.col = 6, .line = 6},
        {.col = 6, .line = 6},
        {.col = 6, .line = 6},
        {.col = 6, .line = 7}
    };

    if (pos && ((turn + 1) >= sizeof(pos) / sizeof(pos[0])))
        return ERROR;
//    usleep(100000);
    send_info(navy->enemy_pid, HIT);
    if (navy->player_id == SIGUSR1 && !turn) {
        my_printf("attack:  %c%c\n", 'A', '2');
        request_position((pos_t) {.col = 0, .line = 0}, navy);
        hit_target(game, (pos_t) {.col = 0, .line = 0}, navy);
    } else {
        my_printf("attack:  %c%c\n", (pos[turn]).col + 'A', (pos[turn]).line + '1');
        request_position(pos[turn], navy);
        hit_target(game, pos[turn], navy);
    }
}

uint8_t player_turn(navy_t *navy, game_t *game)
{
    pos_t pos;

    if (navy->player_id == SIGUSR1)
        print_board(navy->map, navy->enemy_map);

    static int turn = 0;

    if (test(navy, game,turn) != ERROR) {
        turn += 1;
    }
    else {
        usleep(100000);
        if ((pos = get_user_input(navy, game)).line == ERROR)
            return ERROR;
        request_position(pos, navy);
        hit_target(game, pos, navy);
        turn += 1;
    }

    /* if ((pos = get_user_input(navy, game)).line == ERROR) */
    /*     return ERROR; */
    /* request_position(pos, navy); */
    /* hit_target(game, pos, navy); */

    game->turn = false;
    return game->win;
}

static void request_position(pos_t pos, navy_t *navy)
{
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

static void signal_handler(int signum)
{
    if (signum == SIGUSR1 || signum == SIGUSR2)
        return;
}

static pos_t get_user_input(navy_t *navy, game_t *game)
{
    char *input = NULL;

    /* my_printf("passe dans get_user_input\n"); */
    /* signal(SIGUSR1, signal_handler); */
    /* signal(SIGUSR2, signal_handler); */
    do {
        my_printf("attack:  ");
        input = get_next_line(0u);
        /* if (!input) */
        /*     continue; */
        /* my_printf("inp: %s\n", input ? input : "false"); */
        /* usleep(10000); */
        if (!input) {
            my_printf("passe dans no input\n");
            game->play = false;
            print_board(navy->map, navy->enemy_map);
            send_info(navy->enemy_pid, STOP_GAME);
            return ((pos_t) {.line = ERROR, .col = ERROR});
        /* } */
        } else
            send_info(navy->enemy_pid, HIT);
    } while (!check_user_synthax(input));
    return ((pos_t) {.col = *input - 'A', .line = *(input + 1) - '1'});
}

static bool check_user_synthax(char *input)
{
    if (!input)
        return false;
    if (my_strlen(input) != 2) {
        my_printf("wrong position str\n");
        return false;
    }
    /* my_printf("%c\t%c\n", *input, *(input + 1)); */
    /* my_printf("letter: %s", IS_LETTER(*input) ? "true" : "false"); */
    /* my_printf("number: %s", IS_NUMBER(*(input + 1)) ? "true" : "false"); */
    if (IS_LETTER(*input) && IS_NUMBER(*(input + 1)))
        return true;
    else {
        my_printf("wrong position\n");
        return false;
    }
}
