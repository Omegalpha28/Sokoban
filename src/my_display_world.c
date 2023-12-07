/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** display the world
*/
#include <curses.h>
#include <sys/stat.h>
#include "../sokoban.h"

void verif_display_world(char w, int i, int j, element *e)
{
    if (i == e->pos_x && j == e->pos_y)
        my_putstr(e->player);
    else
        my_putchar(w);
}

void my_display_world(char **world, size_tab *s, element *e)
{
    for (int i = 0; i < s->size_col; i++) {
        for (int j = 0; j < s->size_length; j++) {
            verif_display_world(world[i][j], i, j, e);
        }
        my_putstr("\n");
    }
}