/*
** EPITECH PROJECT, 2019
** Navy.
** File description:
** Source file for managing the beginning of the game.
*/

#include <signal.h>
#include "navy.h"

#include "printf.h"

static game_t fill_game_struct(uint8_t player_id);

int play_navy(navy_t *navy)
{
    game_t game = fill_game_struct(navy->player_id);
    uint8_t rcode = 0;

    while (game.play) {
        if (game.turn)
            rcode = player_turn(navy, &game);
        else
            rcode = enemy_turn(navy, &game);
    }
    return (free_board(navy->map, navy->enemy_map, rcode));
}

static game_t fill_game_struct(uint8_t player_id)
{
    return ((game_t) {.turn = (player_id == SIGUSR1) ? true : false,
            .play = true,
            .win = true});
}
