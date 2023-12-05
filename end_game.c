/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** the game is over
*/
#include <curses.h>
#include <sys/stat.h>
#include "sokoban.h"

int verif_end_game(char w)
{
    if (w == 'O') {
        return 1;
    } else {
        return 0;
    }
}

int end_game(char **world, size_tab *s)
{
    int end = 0;

    for (int i = 0; i < s->size_col; i++) {
        for (int j = 0; j < s->size_length; j++) {
            end += verif_end_game(world[i][j]);
        }
    }
    if (end == 0) {
        return 1;
    } else {
        return 0;
    }
}
