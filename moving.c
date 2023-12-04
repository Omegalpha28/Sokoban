/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** these function will display the argument given in the center of the map.
*/
#include <curses.h>
#include <unistd.h>
#include "sokoban.h"

int is_moving_with_box_y(element *e, char **world, int move_x, int move_y)
{
    int playing = 0;

    if (world[e->pos_x + move_x][e->pos_y + move_y * 2] == ' ') {
        world[e->pos_x + move_x][e->pos_y + move_y * 2] = 'X';
        world[e->pos_x + move_x][e->pos_y + move_y] = ' ';
        e->pos_x += move_x;
        e->pos_y += move_y;
    }
    if (world[e->pos_x + move_x][e->pos_y + move_y * 2] == 'O') {
        world[e->pos_x + move_x][e->pos_y + move_y * 2] = 'X';
        world[e->pos_x + move_x][e->pos_y + move_y] = ' ';
        e->pos_x += move_x;
        e->pos_y += move_y;
        playing = -1;
    }
    return playing;
}

int is_moving_with_box_x(element *e, char **world, int move_x, int move_y)
{
    int playing = 0;

    if (world[e->pos_x + move_x * 2][e->pos_y + move_y] == ' ') {
        world[e->pos_x + move_x * 2][e->pos_y + move_y] = 'X';
        world[e->pos_x + move_x][e->pos_y + move_y] = ' ';
        e->pos_x += move_x;
        e->pos_y += move_y;
    }
    if (world[e->pos_x + move_x * 2][e->pos_y + move_y] == 'O') {
        world[e->pos_x + move_x * 2][e->pos_y + move_y] = 'X';
        world[e->pos_x + move_x][e->pos_y + move_y] = ' ';
        e->pos_x += move_x;
        e->pos_y += move_y;
        playing = -1;
    }
    return playing;
}

int is_moving(element *e, char **world, int move_x, int move_y)
{
    int playing = 0;

    if (world[e->pos_x + move_x][e->pos_y + move_y] == ' ' ||
        world[e->pos_x + move_x][e->pos_y + move_y] == 'O') {
        e->pos_x += move_x;
        e->pos_y += move_y;
    }
    if (world[e->pos_x + move_x][e->pos_y + move_y] == 'X') {
        if (move_x != 0)
            playing = is_moving_with_box_x(e, world, move_x, move_y);
        if (move_y != 0)
            playing = is_moving_with_box_y(e, world, move_x, move_y);
    }
    return playing;
}

int moving_player(element *e, char **world, int playing, int t_pressed)
{
    switch (t_pressed) {
    case KEY_UP:
        return (is_moving(e, world, -1, 0));
    case KEY_DOWN:
        return (is_moving(e, world, 1, 0));
    case KEY_LEFT:
        return (is_moving(e, world, 0, -1));
    case KEY_RIGHT:
        return (is_moving(e, world, 0, 1));
    default:
        return 0;
    }
}
