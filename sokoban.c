/*
** EPITECH PROJECT, 2023
** SOKOBAN
** File description:
** it's my main bro
*/
#include <curses.h>
#include <stdio.h>
#include "sokoban.h"
#include <unistd.h>

int sokoban(char **av)
{
    return 0;
}

void my_help(void)
{
    my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n     map  file ");
    my_putstr("representing the warehouse map, containing ‘#’ for walls,\n");
    my_putstr("          ");
    my_putstr("‘P’ for the player, ‘X’ for boxes and ‘O’ for storage ");
    my_putstr("locations.\n");
}

int is_help(char **av)
{
    if (my_strcmp(av[1], "-h") == 0) {
        my_help();
        return 0;
    } else {
        write(2, "Nope!\n", 7);
        return 84;
    }
}

int main(int ac, char **av)
{
    if (ac == 2) {
        return(is_help(av));
    } else if (ac == 1) {
        sokoban(av);
    } else {
        write(2, "Nope!\n", 7);
        return 84;
    }
}
