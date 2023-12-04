##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## SIUUUUUUUUUU look at this Makefile it work.
##

SRC = mp_something.c \
	my_strcmp.c \
	my_display_in_center.c \
	my_convert_tab.c \
	help_and_open_file.c \
	search_player.c \
	search_goal.c \
	moving.c \
	my_box.c

FILE_O = *.o
LIBMY_A = libmy.a
INCLUDE = include
CONV = $(SRCS:.c=.o)
SOKOBAN = sokoban


$(SOKOBAN):
	gcc -c $(SRC) -Iinclude
	ar rcs $(LIBMY_A) $(FILE_O)
	gcc -c sokoban.c $(LIBMY_A) -Iinclude
	gcc -o $(SOKOBAN) sokoban.c $(LIBMY_A) -lncurses -Iinclude -g3
	make clean

clean:
	find -type f -iname '*.o' -delete
	find -type f -iname '*.a' -delete

fclean:
	make clean
	rm -f $(SOKOBAN)

re:
	make fclean
	make
