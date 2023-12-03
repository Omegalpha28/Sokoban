/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** it's my main bro
*/
#include <curses.h>
#include <sys/stat.h>
#include "sokoban.h"

int is_goal(char **world, size_tab *s, int i, int j)
{
    if (world[i][j] == 'O')
        return 1;
    return 0;
}

int search_goal(char **world, size_tab *s)
{
    int goal = 0;

    for (int i = 0; i != s->size_col; i++) {
        for (int j = 0; j != s->size_length ; j++) {
            goal += is_goal(world, s, i, j);
        }
    }
    return goal;
}