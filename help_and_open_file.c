#include <fcntl.h>
#include "sokoban.h"
#include <unistd.h>

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
    int fd = 0;

    if (my_strcmp(av[1], "-h") == 0) {
        my_help();
        return 0;
    }
    fd = open(av[1], O_RDONLY);
    if (fd != -1) {
        return (sokoban(av, fd));
    } else {
        write(2, "Nope!\n", 7);
        return 84;
    }
}
