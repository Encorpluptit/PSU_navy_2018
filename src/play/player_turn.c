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
    /* pos_t pos[] = { */
    /*     {.col = 0, .line = 2}, */
    /*     {.col = 0, .line = 1}, */
    /*     {.col = 1, .line = 2}, */
    /*     {.col = 3, .line = 3}, */
    /*     {.col = 3, .line = 4}, */
    /*     {.col = 3, .line = 5}, */
    /*     {.col = 4, .line = 1}, */
    /*     {.col = 5, .line = 1}, */
    /*     {.col = 6, .line = 1}, */
    /*     {.col = 7, .line = 1}, */
    /*     {.col = 6, .line = 3}, */
    /*     {.col = 6, .line = 4}, */
    /*     {.col = 6, .line = 5}, */
    /*     {.col = 6, .line = 6}, */
    /*     {.col = 6, .line = 6}, */
    /*     {.col = 6, .line = 6}, */
    /*     {.col = 6, .line = 6}, */
    /*     {.col = 6, .line = 6}, */
    /*     {.col = 6, .line = 6}, */
    /*     {.col = 6, .line = 6}, */
    /*     {.col = 6, .line = 6}, */
    /*     {.col = 6, .line = 6}, */
    /*     {.col = 6, .line = 6}, */
    /*     {.col = 6, .line = 6}, */
    /*     {.col = 6, .line = 7} */
    /* }; */

    /* send_info(navy->enemy_pid, HIT); */
    /* if (navy->player_id == SIGUSR2 && !turn) { */
    /*     my_printf("attack:  %c%c\n", 'A', '2'); */
    /*     request_position((pos_t) {.col = 0, .line = 0}, navy); */
    /*     hit_target(game, (pos_t) {.col = 0, .line = 0}, navy); */
    /* } else { */
    /*     my_printf("attack:  %c%c\n", (pos[turn]).col + 'A', (pos[turn]).line + '1'); */
    /*     request_position(pos[turn], navy); */
    /*     hit_target(game, pos[turn], navy); */
    /* } */
    /* return SUCCESS; */

    static uint8_t col = 0;
    static uint8_t line = 0;
    static uint32_t stop = 0;

    if (col > 7) {
        col = 0;
        line ++;
    }
    if (line >= 7 && col >= 6) {
        stop++;
        col = 0;
        line = 0;
    }
    my_printf("STOP = %d\n", stop);
    if (stop > 400) {
        my_printf("STOP = %d\n", stop);
        return ERROR;
    }
    pos_t pos = (pos_t) {.line = line, .col = col};

    /* if (pos && ((turn + 1) >= sizeof(pos) / sizeof(pos[0]))) */
    /*     return ERROR; */
    usleep(2000);
    send_info(navy->enemy_pid, HIT);
    if (navy->player_id == SIGUSR2 && !turn) {
        my_printf("attack:  %c%c\n", 'A', '2');
        usleep(2000);
        request_position((pos_t) {.col = 0, .line = 0}, navy);
        hit_target(game, (pos_t) {.col = 0, .line = 0}, navy);
    } else {
        my_printf("attack:  %c%c\n", (pos).col + 'A', (pos).line + '1');
        usleep(2000);
        request_position(pos, navy);
        hit_target(game, pos, navy);
    }
    col++;
    return SUCCESS;
}

uint8_t player_turn(navy_t *navy, game_t *game)
{
    pos_t pos;

    if (navy->player_id == SIGUSR1)
        print_board(navy->map, navy->enemy_map);
    usleep(2000);
    static int turn = 0;
    if (test(navy, game,turn) != ERROR) {
        turn += 1;
    }
    else {
        usleep(2000);
        if ((pos = get_user_input(navy, game)).line == ERROR)
            return QUIT;
        request_position(pos, navy);
        hit_target(game, pos, navy);
        turn += 1;
    }

    /* if ((pos = get_user_input(navy, game)).line == ERROR) */
    /*         return QUIT; */
    /* request_position(pos, navy); */
    /* hit_target(game, pos, navy); */

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
        my_printf("wrong position str\n");
        return false;
    }
    if (IS_LETTER(*input) && IS_NUMBER(*(input + 1)))
        return true;
    else {
        my_printf("wrong position\n");
        return false;
    }
}
