##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## SIUUUUUUUUUU look at this Makefile it work.
##

SRC = mp_something.c \
	my_strcmp.c

FILE_O = *.o
LIBMY_A = libmy.a
INCLUDE = include
CONV = $(SRCS:.c=.o)
SOKOBAN = sokoban


$(SOKOBAN):
	gcc -c $(SRC) -Iinclude
	ar rcs $(LIBMY_A) $(FILE_O)
	gcc -c sokoban.c $(LIBMY_A) -Iinclude
	gcc -o $(SOKOBAN) sokoban.c $(LIBMY_A) -Iinclude -g3
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
