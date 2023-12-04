/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** it'll check if my box is blocked or not
*/
#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"

int verify_box(char **world, int i, int j)
{
    int wall_count = 0;

    if (world[i][j] == 'X') {
        if (world[i - 1][j] == '#') {
            wall_count++;
        }
        if (world[i  + 1][j] == '#') {
            wall_count++;
        }
        if (world[i][j - 1] == '#') {
            wall_count++;
        }
        if (world[i][j + 1] == '#') {
            wall_count++;
        }
    }
    return wall_count;
}

int my_box_is_here(char **world, int i, int j)
{
    if (world[i][j] == 'X') {
        return 1;
    } else {
        return 0;
    }
}

int comparate_my_box(int blocked, int count_box_stuck, int search_goal,
    size_tab *s)
{
    if (count_box_stuck == search_goal) {
        s->playing = 0;
        s->stuck = 1;
    }
    if (blocked >= 2) {
        return 1;
    } else {
        return 0;
    }
}

void my_box(char **world, size_tab *s, int search_goal)
{
    int blocked = 0;
    int count_box_stuck = 0;

    for (int i = 0; i < s->size_col; i++) {
        for (int j = 0; j < s->size_length; j++) {
            blocked = verify_box(world, i, j);
            count_box_stuck += comparate_my_box(blocked, count_box_stuck,
                search_goal, s);
        }
    }
}
