/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** give the number of goal
*/
#include <curses.h>
#include <sys/stat.h>
#include "../sokoban.h"

int is_goal(char **world, element *e, int i, int j)
{
    if (world[i][j] == e->goal)
        return 1;
    return 0;
}

int search_goal(char **world, size_tab *s, element *e)
{
    int goal = 0;

    for (int i = 0; i != s->size_col; i++) {
        for (int j = 0; j != s->size_length ; j++) {
            goal += is_goal(world, e, i, j);
        }
    }
    return goal;
}
