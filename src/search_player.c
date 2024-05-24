/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** these functions will search the player's position
*/
#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../sokoban.h"

void where_is_player(char **world, element *e, int i, int j)
{
    if (world[i][j] == 'P') {
        e->pos_x = i;
        e->pos_y = j;
    }
}

void search_player(char **world, element *e)
{
    for (int i = 0; world[i] != NULL; i++) {
        for (int j = 0; world[j] != NULL; j++) {
            where_is_player(world, e, i, j);
        }
    }
}

void where_is_box(char **world, element *e, int i, int j)
{
    if (world[i][j] == 'X') {
        e->pos_x = i;
        e->pos_y = j;
    }
}

void search_box(char **world, element *e)
{
    for (int i = 0; world[i] != NULL; i++) {
        for (int j = 0; world[j] != NULL; j++) {
            where_is_player(world, e, i, j);
        }
    }
}
