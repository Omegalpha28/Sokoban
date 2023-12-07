##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## SIUUUUUUUUUU look at this Makefile it work.
##

SRC = src/mp_something.c \
	src/my_strcmp.c \
	src/my_display_in_center.c \
	src/my_convert_tab.c \
	src/help_and_open_file.c \
	src/search_player.c \
	src/search_goal.c \
	src/moving.c \
	src/my_box.c \
	src/my_convert_tab_void.c \
	src/compare_world.c \
	src/end_game.c

FILE_O = *.o
LIBMY_A = libmy.a
SOKOBAN = my_sokoban


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
