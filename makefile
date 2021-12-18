.PHONY = all clean
all: stringProg
FLAGS = -Wall -Werror -g
CC = gcc
stringProg: Ex3.c
	$(CC) $(FLAGS) Ex3.c -o stringProg
clean:
	rm -f *.o *.a stringProg
