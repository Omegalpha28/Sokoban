/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** moving the player and the boxes
*/
#include <curses.h>
#include <unistd.h>
#include "../sokoban.h"

int is_moving_with_box_y(element *e, char **world, int move_y)
{
    if (world[e->pos_x][e->pos_y + move_y * 2] == ' ' ||
        world[e->pos_x][e->pos_y + move_y * 2] == 'O') {
        world[e->pos_x][e->pos_y + move_y * 2] = 'X';
        world[e->pos_x][e->pos_y + move_y] = ' ';
        e->pos_y += move_y;
    }
    return 0;
}

int is_moving_with_box_x(element *e, char **world, int move_x)
{
    if (world[e->pos_x + move_x * 2][e->pos_y] == ' ' ||
        world[e->pos_x + move_x * 2][e->pos_y] == e->goal) {
        world[e->pos_x + move_x * 2][e->pos_y] = e->box;
        world[e->pos_x + move_x][e->pos_y] = ' ';
        e->pos_x += move_x;
    }
    return 0;
}

int is_moving_with_box(element *e, char **world, int move_x, int move_y)
{
    if (move_x != 0)
        is_moving_with_box_x(e, world, move_x);
    if (move_y != 0)
        is_moving_with_box_y(e, world, move_y);
    return 0;
}

int is_moving(element *e, char **world, int move_x, int move_y)
{
    if (world[e->pos_x + move_x][e->pos_y + move_y] == ' ' ||
        world[e->pos_x + move_x][e->pos_y + move_y] == e->goal) {
        e->pos_x += move_x;
        e->pos_y += move_y;
    } else if (world[e->pos_x + move_x][e->pos_y + move_y] == e->box) {
        is_moving_with_box(e, world, move_x, move_y);
    }
    return 0;
}

int moving_player(element *e, char **world, char **back_world, int t_pressed)
{
    switch (t_pressed) {
    case KEY_UP:
        is_moving(e, world, -1, 0);
        break;
    case KEY_DOWN:
        is_moving(e, world, 1, 0);
        break;
    case KEY_LEFT:
        is_moving(e, world, 0, -1);
        break;
    case KEY_RIGHT:
        is_moving(e, world, 0, 1);
        break;
    default:
        break;
    }
}
