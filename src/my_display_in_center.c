/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** these function will display the argument given in the center of the map.
*/
#include <curses.h>
#include <unistd.h>
#include "../sokoban.h"

void test(char w, int i, int j, element *e)
{
    if (i == e->pos_x && j == e->pos_y)
        printw(e->player);
    else
        printw("%c", w);
}

void my_display_in_center(WINDOW *stdscr, char **world, size_tab *s,
    element *e)
{
    clear();
    for (int i = 0; i < s->size_col; i++) {
        for (int j = 0; j < s->size_length; j++) {
            test(world[i][j], i, j, e);
        }
        printw("\n");
    }
    refresh();
}
